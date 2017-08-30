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
void NewGateway1(void*message,const char*name)
{
	auto recv = static_cast<GateServer::NewGate*>(message);
	if(recv == nullptr){
		return ;
	}

	std::cout<<"dwID ="<<recv->dwid()<<std::endl;
	std::cout<<"straddr = "<<recv->strip()<<std::endl;
	
}






void LoginMessage::InitMessageCallBack()
{
	_socket->AddMessageCallBack("GateServer.UserLogin",std::bind(NewGateway1,std::placeholders::_1,std::placeholders::_2));
}


