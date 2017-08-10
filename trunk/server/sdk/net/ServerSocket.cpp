#include "ServerSocket.h"
#include "Protobuf.h"
using namespace sdk;
#define SOCKET_BUFFER_SIZE 1024*100
bool ServerSocket::Init(Json::Document& config){
	if(!config.IsObject()){
		return false;
	}
	auto& type = config["type"];
	if(type.IsNull()){
		return false;
	}
	if(!type.IsInt()){
		return false;
	}
	_type = static_cast<const SocketType>(type.GetInt());
	

	auto& proto = config["proto"];
	if(proto.IsNull()){
		return false;
	}

	if(!proto.IsString()){
		return false;
	}

	_address = proto.GetString();

	auto& timeOut = config["proto"];
	if(!timeOut.IsNull()){
		if(timeOut.IsInt()){
		_timeOut = proto.GetInt();
		}
	}
	


	void *ctx = zmq_ctx_new();
	assert(ctx);
	int zmqSocketType = SwitchSocketType(_type);
	_socket = zmq_socket(ctx,zmqSocketType);
	if(_socket == nullptr){
		return false;
	}

	int rc  = zmq_bind(_socket,_address.c_str());
	if(rc == 0){
		return false;
	}; 

	zmq_setsockopt(_socket,ZMQ_RCVTIMEO,&_timeOut,sizeof(_timeOut));

	return true;
}

bool ServerSocket::Run()
{
	char buffer[SOCKET_BUFFER_SIZE];
	while(true)
	{
		int recv_size = zmq_recv(_socket,buffer,sizeof(buffer),0);   
		if(recv_size <0){   
			continue;
		}
		recv_size = zmq_send(_socket,buffer,recv_size,0);
	}

	return true;
}

int ServerSocket::SwitchSocketType(const SocketType &type)
{
	switch(type)
	{
		case SocketType::SOCKET_TYPE_REQ:
			return ZMQ_REQ;
		case SocketType::SOCKET_TYPE_REP:
			return ZMQ_REP;
		case SocketType::SOCKET_TYPE_DEALER:
			return ZMQ_DEALER;
		case SocketType::SOCKET_TYPE_ROUTER:
			return ZMQ_ROUTER;
		case SocketType::SOCKET_TYPE_PUB:
			return ZMQ_PUB;
		case SocketType::SOCKET_TYPE_SUB:
			return ZMQ_SUB;
	}

	return -1;
}

SocketType ServerSocket::GetSocketType(){
	return _type;
}

void ServerSocket::SendMessage(const ProtoBuffMessage& message){


}
