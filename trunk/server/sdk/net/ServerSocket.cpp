#include "ServerSocket.h"
#include "Protobuf.h"
using namespace sdk;
#define SOCKET_BUFFER_SIZE 1024
bool ServerSocket::Init(Json::Value& value){
	if(!value.IsObject()){
		return false;
	}
	auto& config = value;

	auto& type = config["type"];
	if(type.IsNull()){
		return false;
	}
	if(!type.IsInt()){
		return false;
	}
	_type = static_cast<const SocketType>(type.GetInt());

	if(config.HasMember("timeout"))
	{
		auto& timeOut = config["timeout"];
		if(!timeOut.IsNull()){
			if(timeOut.IsInt()){
				_timeOut = timeOut.GetInt();
			}
		}
	}

	void *ctx = zmq_ctx_new();
	assert(ctx);
	int zmqSocketType = SwitchSocketType(_type);
	_socket = zmq_socket(ctx,zmqSocketType);
	assert(_socket != nullptr);
	zmq_setsockopt(_socket,ZMQ_RCVTIMEO,&_timeOut,sizeof(_timeOut));
	if(config.HasMember("bind_addr"))
	{
		auto& bind_addr = config["bind_addr"];
		if(bind_addr.IsNull()){
			return false;
		}
		if(!bind_addr.IsString()){
			return false;
		}
		_address = bind_addr.GetString();
		int rc  = zmq_bind(_socket,_address.c_str());
		assert(rc == 0);
	}
	else
	{
		auto& connect_addr = config["connect_addr"];
		if(connect_addr.IsNull()){
			return false;
		}
		if(!connect_addr.IsString()){
			return false;
		}
		int rt = zmq_connect(_socket,connect_addr.GetString());
		assert(rt == 0);
	}
	return true;
}

bool ServerSocket::Run()
{
	char buffer[SOCKET_BUFFER_SIZE];
	while(true)
	{
		int recv_size = zmq_recv(_socket,buffer,SOCKET_BUFFER_SIZE,0);   
		if(recv_size <0){   
			continue;
		}
		MessageDel(buffer);
	}

	return true;
}

int ServerSocket::SwitchSocketType(const SocketType &type)
{
	switch(type)
	{
		case SocketType::SOCKET_TYPE_NONE:
			return -1;
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
	char buffer[SOCKET_BUFFER_SIZE ];
	auto size = decode(buffer,message);
	//int sendsize = zmq_send(_socket,buffer,size,0);
	 zmq_send(_socket,buffer,size,0);
//	printf("send size %d\n",sendsize);
}
