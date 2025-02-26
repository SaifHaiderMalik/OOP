
#define _WIN32_WINNT 0x0600

#include <iostream>
#include <WS2tcpip.h>
#include <string>

#pragma comment (lib, "WS2_32.lib")

using namespace std;

int inet_pton(int af, const char *src, void *dst)
{
  struct sockaddr_storage ss;
  int size = sizeof(ss);
  char src_copy[INET6_ADDRSTRLEN+1];

  ZeroMemory(&ss, sizeof(ss));
  /* stupid non-const API */
  strncpy (src_copy, src, INET6_ADDRSTRLEN+1);
  src_copy[INET6_ADDRSTRLEN] = 0;

  if (WSAStringToAddress(src_copy, af, NULL, (struct sockaddr *)&ss, &size) == 0) {
    switch(af) {
      case AF_INET:
    *(struct in_addr *)dst = ((struct sockaddr_in *)&ss)->sin_addr;
    return 1;
      case AF_INET6:
    *(struct in6_addr *)dst = ((struct sockaddr_in6 *)&ss)->sin6_addr;
    return 1;
    }
  }
  return 0;
}

const char *inet_ntop(int af, const void *src, char *dst, socklen_t size)
{
  struct sockaddr_storage ss;
  unsigned long s = size;

  ZeroMemory(&ss, sizeof(ss));
  ss.ss_family = af;

  switch(af) {
    case AF_INET:
      ((struct sockaddr_in *)&ss)->sin_addr = *(struct in_addr *)src;
      break;
    case AF_INET6:
      ((struct sockaddr_in6 *)&ss)->sin6_addr = *(struct in6_addr *)src;
      break;
    default:
      return NULL;
  }
  /* cannot direclty use &size because of strict aliasing rules */
  return (WSAAddressToString((struct sockaddr *)&ss, sizeof(ss), NULL, dst, &s) == 0)?
          dst : NULL;
}

int main(){
    //Initiallize winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);
    if(wsOk != 0){
        cerr << "Can't Initialize winsock! Quitting" << endl;
        return 0;
    }

    //Create a socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if(listening == INVALID_SOCKET){
        cerr << "Can't create a socket! Quitting" << endl;
        return 0;
    }

    //Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY; //Could also use inet_pton...

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    //Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

    //Wait for a connection
    sockaddr_in client;
    int clientSize = sizeof(client);

    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];      //Client's remote name
    char service[NI_MAXSERV];   //Service (i.e. port) the client is connect on

    ZeroMemory(host, NI_MAXHOST);    //same as memset(host, 0, NI_MAXHOST);
    ZeroMemory(service, NI_MAXSERV);

    if(getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
        cout << host << " connected on port " << service << endl;
    }
    else{
        //WSAAddressToString((LPSOCKADDR)&client, sizeof(client),)
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        //inet_ntoa(client.sin_addr);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    //Close listening socket
    closesocket(listening);

    //While loop: accept and echo message back to client
    char buf[4096];

    while(true){
        ZeroMemory(buf, 4096);
        
        //Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if(bytesReceived == SOCKET_ERROR){
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if(bytesReceived == 0){
            cout << "Client disconnected " << endl;
            break;
        }

        cout << string(buf, 0, bytesReceived) << endl;

        //Echo message back to client
        send(clientSocket, buf, bytesReceived + 1, 0);
    }
    
    //Close the socket
    closesocket(clientSocket);

    //Cleanup winsock
    WSACleanup();

    system("pause");
}