#include "LoginMessage.h"
bool LoginMessage::Init(ServerSocket& socket)
{
	_socket = &socket;
	InitMessage();
	InitMessageCallBack();
	return true;
}

void LoginMessage::InitMessage()
{

	{GateServer::UserLogin s;}
}
void LoginMessage::NewGateway1(void*message,const char*name)
{
	auto recv = static_cast<GateServer::NewGate*>(message);
	if(recv == nullptr){
		return ;
	}

	std::cout<<"dwID ="<<recv->dwid()<<std::endl;
	std::cout<<"straddr = "<<recv->strip()<<std::endl;
	std::cout<<"gatename=" <<name<<std::endl;
	LoginProto::Result ret;
	ret.set_dwid(1);
	ret.set_result(2);
	_socket->Send(name,ret);
	
}





void LoginMessage::InitMessageCallBack()
{
	_socket->AddMessageCallBack("GateServer.UserLogin",std::bind(&LoginMessage::NewGateway1,this,std::placeholders::_1,std::placeholders::_2));
}


