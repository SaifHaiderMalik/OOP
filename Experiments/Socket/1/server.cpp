#include "server.h"

using namespace std;

int main(){
    long SUCCESSFUL;
    WSAData WinSockData;
    WORD DLLVERSION;

    //WORD = objects of a data size that a processor naturally handles (16 or 32-bit)
    DLLVERSION = MAKEWORD(2, 1);

    /*
    WSAStartup(WORD, WSAData) starts the Winsock API
    typedef struct WSAData{
        WORD wVersion;
        WORD wHighVersion;
        char szDescription[WSADESCRIPTION_LEN+1];
        char szSystemStatus[WSASYS_STATUS_LEN+1];
        unsigned short int iMaxSockets;
        unsigned short int iMaxUdpDg;
        char * IpVendorInfo;
    }
    */
    
    SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);
    
    /*
    WSACleanup() Stops Winsock API (Terminates use of the Winsock WS2_32.dll) - int type
    */

    /*
    struct SOCKADDR_IN{             //Structure to define Internet Address
        short sin_family;           //Specifies Address Family, usually "AF_INET"
        u_short sin_port;           //Port Number must be used with htons() which converts "host byte order" to "network byte order"
        struct in_addr sin_addr;    //IP ADDRESS returned by inet_addr()
        char sin_zero[8];           //char array buffer usually set to zero
    }
    */
    SOCKADDR_IN ADDRESS;
    int AddressSize = sizeof(ADDRESS);

    //Creates Sockets
    SOCKET sock_LISTEN;     //Listen for incoming Connections
    SOCKET sock_CONNECTION; //activates when connection found

    /*
    socket(int AF, int TYPE, int PROTOCOL)  Initiates TCP/UDP socket connection
    socket(AF_INET, SOCK_STREAM, NULL) Initiates TCP Socket
    send(SOCKET, char *buffer, LENGTH, FLAGS) Sends data with TCP sockets
    recv(SOCKET, char *buffer, LENGTH, FLAGS) Receives Data with TCP Sockets
    socket(AF_INET, SOCK_DGRAM, NULL) Initiates UDP Socket
    sendto(SOCKET, char *buffer, LENGTH, FLAGS, SOCK ADDR, ADDR LENGTH) Sends data with UDP sockets
    recvfrom(SOCKET, char *buffer, LENGTH, FLAGS, SOCK ADDR, ADDR LENGTH) Receives Data with UDP Sockets
    */

   //socket arguments: AF_INET = Internet Domain (not Unix Domain)
    sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
    ADDRESS.sin_family = AF_INET;
    ADDRESS.sin_port = htons(444);

    sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);

    //Binds socket to SOCKADDR_IN Structure
    bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

    //listen(SOCKET, MAX CONNECTIONS) Tells socket to listen for incoming connections on socket with max allowed connections
    //SOMAXCONN is whatever allowed for the System
    listen(sock_LISTEN, SOMAXCONN);
    
    /*
    closesocket(SOCKET) closes and open Socket
    */

   //If connection found
    for(;;){
        cout << "\n\tSERVER: waiting for incoming connection...";

        /*
        accept(SOCKET, SOCK ADDR, ADDR LENGTH)
        Waits for connection and wakes when a connection is established.
        Usually used at Server part in client-Server Apps.
        */
        if(sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize)){
            cout << "\n\tA Connection was found!" << endl;

            SUCCESSFUL = send(sock_CONNECTION, "Welcome you have connected to Banana Server!", 46, NULL);
        }
    }

    //return 0;
}