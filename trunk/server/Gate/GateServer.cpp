#include <stdio.h>
#include <iostream>
#include <iostream>
#include <string.h>
#include "GateServer.h"
#include "../sdk/sdk.h"
#include "../proto/ProtobufList.h"
using namespace std;
using namespace sdk;
ServerSocket *globalSocket;
int globalIndex = 0;
void Result(void*arg,const char*){

auto recv = static_cast<LoginProto::Result*> (arg);

if(recv == nullptr){
	return ;
}




cout<<"recv message"<<endl;
cout<<"dwid ="<< recv->dwid()<<endl;

//	auto msg = static_cast<LoginProto::Result*>(arg);
//	if(msg == nullptr){
//		return ;
//	}
//
//	std::cout<<msg->dwid()<<msg->result()<<std::endl;
//
//	GateServer::UserLogin send;
//	send.set_dwid(msg->dwid()+1);
//	send.set_str ( "wwwww");
//	globalSocket->SendMessage(send);
//	printf("i=%d\n",msg->dwid());
//


}

void NewGate(){

//	GateServer::NewGate send;
//	send.set_dwid(globalIndex);
//	send.set_strip ( "wwwww");
//	globalSocket->Send("Login",send);
};

void SendToLogin(void *arg){
	GateServer::UserLogin send;
	send.set_dwid(globalIndex);
	send.set_str ( "wwwww");
	globalSocket->SendToAll(send);
	printf("globalIndex=%d\n",globalIndex);
	++globalIndex;
}


int main(int argc,char * argv[])
{


	{GateServer::UserLogin s;}
	{GateServer::NewGate s;}
	{LoginProto::Result s;}

	ServerSocket socket;
	globalSocket = &socket;
	Json::Document doc;
	JsonManager::ParseFile("/home/sauli/server/cfg/servercfg/ipcfg.json",doc);    
	const char* config = "Gate1";
	if(argc>=2)
	{
		config = argv[1];	
	}


	assert(socket.Init(doc[config]));
	socket.AddMessageCallBack("LoginProto.Result",Result);
	SendToLogin(nullptr);
	NewGate();

		SendToLogin(nullptr);
	while(true)
	{
		socket.Loop();
	//	SendToLogin(nullptr);
		usleep(200);
	}


//socket .AddMessageCallBack("TextProto::Login",std::bind(SendToLogin,std::placeholders::_1));







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
