#include "sSocket.h"
#define BUFFER_SIZE 1024
using namespace sdk;
bool sSocket::Init(const std::string& ipPort)
{
	_ctx = zmq_ctx_new();
	if(_ctx == nullptr){
		return false;
	}

	_socket = zmq_socket(ctx,ZMQ_DEALER);
	if(_ctx == nullptr){
		return false;	
	}

	int rc  = zmq_bind(socket,ipPort.c_str());
	if(rc != 0){
		return false;
	}

	zmq_setsockopt(socket,ZMQ_RCVTIMEO,&_overTime,sizeof(timeOut)))

	return true;
}


void sSocket::sendMessage(const MSG& message)
{

//int client_sock = accept(server_sock, NULL, NULL);
	char buffer[BUFFER_SIZE]={0};
	_protobufManage.decode(buffer,message);
	zmq_send(_socket,buffer,BUFFER_SIZE,0);

}
