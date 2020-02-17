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
#include <winsock2.h>
#include<ws2tcpip.h>

#pragma comment(lib,"ws2_32.lib");

using namespace std;

int main(){
	string ipaddress = "127.0.0.1";
	int port = 54000;  
	
	 WSADATA wsData;
    WORD ver = MAKEWORD(2,2);
    int wsresult = WSAStartup(ver,&wsData);
    if(wsresult != 0){
    	cout<< "Can't initialize winsock Quiting" << endl;
    	return 0;
	}
	 
	 SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	 if(sock==INVALID_SOCKET){
	 	cerr<<"can't create socket"<<endl;
	 	WSACleanup();
	 	return 0;
	 }
	
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipaddress.c_str(),&hint.sin_addr);
	
	int connresult = connect(sock,(sockaddr*)&hint, sizeof(hint));
	if(connresult==SOCKET_ERROR){
		cerr << "can't connet to server"<<endl;
		WSACleanup();
		return 0;
	}
	
	char buf[4096];
	string userinput;
	
	do{
		cout<<">";
		getline(cin,userinput);
		
		if(userinput.size()>0){
			
	    int sendresult = send(sock,userinput.c_str(),userinput.size()+1,0);
	    if(sendresult!= SOCKET_ERROR){
	    	ZeroMemory(buf,4096);
	    	int bytereceived = recv(sock,buf,4096,0);
	    	if(bytereceived>0){
	    		cout<<"server"<<string(buf,0,bytereceived)<<endl;
			}
		}
	}
	}while(userinput.size()>0);
	
	closesocket(sock);
	WSACleanup();
	
}
