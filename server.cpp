#ifndef WINVER
#define WINVER 0x0600
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#ifndef NTDDI_VERSION
#define NTDDI_VERSION 0x06000000
#endif
#include<iostream>
#include<ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
int main(){
	//initialize winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2,2);
    int wsok = WSAStartup(ver,&wsData);
    if(wsok != 0){
    	cout<< "Can't initialize winsock Quiting" << endl;
    	return 0;
	}
	
//    socket creation
    SOCKET listening = socket(AF_INET,SOCK_STREAM,0);
    if(listening == INVALID_SOCKET){
    	cout << "can't connect to the socket Quitting";
    	return 0;
	}
	
//	bind the ip address and port to socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(listening, (sockaddr*)&hint, sizeof(hint));
	
//	  tell winsock the socket is for listening
	  listen(listening, SOMAXCONN);
	  
	  sockaddr_in client;
	  int clientSize = sizeof(client);
	  SOCKET clientsocket = accept(listening,(sockaddr*)&client,&clientSize);
	  char host[NI_MAXHOST];
	  char service[NI_MAXHOST];
	  
	  ZeroMemory(host,NI_MAXHOST);
	  ZeroMemory(service,NI_MAXHOST); 
	  
	  if(getnameinfo((sockaddr*)&client,sizeof(client),host,NI_MAXHOST,service,NI_MAXSERV,0)==0)
	  {
	  	cout << host << "connected on port "<<service<<endl;	  }
	  else{
	  	inet_ntop(AF_INET, &client.sin_addr,host,NI_MAXHOST);
	  	cout<<host<<"connected on port"<<endl;
	  }
	  closesocket(listening);
	  char buf[4096];
	  while(true){
	  	ZeroMemory(buf,4096);
	  	int byteReceived = recv(clientsocket,buf,4096,0);
	  	if(byteReceived == SOCKET_ERROR){
	  		cout<<"error in recv()"<<endl;
	  		break;
		  }
		  if(byteReceived == 0){
		  	cout<<"Client disconnected"<<endl;
		  	break;
		  }
		  cout<< string(buf,0,byteReceived)<<endl;
		  send(clientsocket,buf,byteReceived+1,0);
	  }
	  		  closesocket(clientsocket);
		  WSACleanup();
	  


}

