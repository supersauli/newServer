#include "sServer.h"
bool sServer::Init()
{
	_socket.Init();
	_socket.SetAddClient(std::bind(&sSctpPool::NewClient,&_pool,std::placeholders::_1 ));
	return true;
}

bool sServer::LoadConfig(const char*  configName)
{
	_socket.SetIpAddress("127.0.0.1");
	_socket.SetPort(4096);
	_pool.SetPthreadMax(1);
	return true;
}

bool sServer::Loop(){
	_pool.InitPool();
	_socket.Bind();
	_socket.Loop();
}


