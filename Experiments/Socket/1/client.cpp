#include "client.h"

using namespace std;

int main(){
    long SUCCESSFUL;
    WSAData WinSockData;
    WORD DLLVERSION;

    DLLVERSION = MAKEWORD(2, 1);

    SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

    string RESPONSE, CONVERTER;
    char MESSAGE[200];

    SOCKADDR_IN ADDRESS;
    //int AddressSize = sizeof(ADDRESS);

    //SOCKET sock_LISTEN;
    //SOCKET sock_CONNECTION;
    SOCKET sock;

    sock = socket(AF_INET, SOCK_STREAM, NULL);

    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
    ADDRESS.sin_family = AF_INET;
    ADDRESS.sin_port = htons(444);

    cout << "\n\tCLIENT: Do you want to connect to this Server? (Y/N) ";
    cin >> RESPONSE;

    RESPONSE[0] = tolower(RESPONSE[0]);

    if(RESPONSE == "n"){
        cout << "\n\tOK Quitting instead.";
    }
    else if(RESPONSE == "y"){
        /*
        connect(SOCKET, SOCK ADDR, ADDR LENGTH)
        connects client to the server at listening state and set to accept connections
        */
        connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

        SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);

        CONVERTER = MESSAGE;

        cout << "\n\tMessage from Server:\n\t" << CONVERTER << endl;
    }
    else{
        cout << "\n\tThat was an inaprpriate respose!";
    }

    cout << "\n\n\t";
    system("pause");
    exit(1);

    //return 0;
}