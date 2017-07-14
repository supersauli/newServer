#include <stdio.h>
#include <iostream>
#include <iostream>
#include <string.h>
#include "Gate.h"
#include "../sdk/sdk.h"
#include "../proto/ProtobufList.h"
using namespace std;
using namespace sdk;
ServerSocket *globalSocket;
int i = 0;
void Result(void*arg){
	auto msg = static_cast<LoginProto::Result*>(arg);
	if(msg == nullptr){
		return ;
	}

	std::cout<<msg->dwid()<<msg->result()<<std::endl;

	GateServer::UserLogin send;
	send.set_dwid(msg->dwid()+1);
	send.set_str ( "wwwww");
	globalSocket->SendMessage(send);
	printf("i=%d\n",msg->dwid());



}

void SendToLogin(void *arg){

	GateServer::UserLogin send;
	send.set_dwid(i);
	send.set_str ( "wwwww");
	globalSocket->SendMessage(send);
	printf("i=%d\n",i);
	i++;
}


int main()
{

	{GateServer::UserLogin s;}
	{LoginProto::Result s;}

	ServerSocket socket;
	globalSocket = &socket;
	Json::Document doc;
	JsonManager::OpenFile("/home/sauli/server/cfg/servercfg/ipcfg.json",doc);    

	assert(socket.Init(doc["Gate"]));
	socket.AddMessageCallBack("LoginProto.Result",Result);
	SendToLogin(nullptr);
	socket.Run();


	while(true)
	{
		SendToLogin(nullptr);
		usleep(1);
	}


	//socket.AddMessageCallBack("TextProto::Login",SendToLogin);










//	SctpSocket socket;
//	socket.SetIpAddress("127.0.0.1");
//	socket.SetPort(4096);
//	if(!socket.Connect()){
//		printf("connect error \n");
//	};
//	socket.Init();
//
//	socket.Write(socket.GetSocket(),"1111111");
//
//	sleep(10);
//	socket.Close(socket.GetSocket());
//
//	sSctpPool sock;
//	if(!sock.Init())
//	{   
//		printf("false\n");
//		return 0;
//
//	};  
//	if(!sock.Bind(2222))
//	{   
//		printf("false\n");  
//		return 0;
//	}   
//
//
//	sock.initPool(1);
//
	//sock.Loop();
}
