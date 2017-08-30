#include "ServerSocket.h"
#include "Protobuf.h"
#include <unistd.h>
using namespace sdk;
#define SOCKET_BUFFER_SIZE 1024*10


const char* ZmqSocket::GetSocketName(){
	return _socketName.c_str();
}

bool ZmqSocket::Init(Json::Value& value)
{
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

	_ctx = zmq_ctx_new();
	assert(_ctx);
	int zmqSocketType = SwitchSocketType(_type);
	_socket = zmq_socket(_ctx,zmqSocketType);
	assert(_socket != nullptr);
	zmq_setsockopt(_socket,ZMQ_RCVTIMEO,&_timeOut,sizeof(_timeOut));
	if(!config.HasMember("name")){
		return false;
	}

	_socketName = config["name"].GetString();

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


ZmqSocket::~ZmqSocket(){
	if(_socket!=nullptr){
		zmq_close(_socket);
	}
	if(_ctx != nullptr){
		zmq_ctx_term(_ctx);
	}

}

int ZmqSocket::SwitchSocketType(const SocketType &type)
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

SocketType ZmqSocket::GetSocketType(){
	return _type;
}

bool ZmqSocket::Recv(char* buffer){
	int recv_size = zmq_recv(_socket,buffer,SOCKET_BUFFER_SIZE,0);   
		if(recv_size >0){   
			return true;
		}
	return false;
}



ServerSocket::~ServerSocket()
{

}

bool ServerSocket::Init(Json::Value& value){

	if(!value.IsArray()){
		return false;
	}

	for(DWORD i =0;i<value.Size();i++)
	{
		auto zmqSocket = std::make_shared<ZmqSocket>();
		if(zmqSocket == nullptr){
			return false;
		}
		if(!zmqSocket->Init(value[i])){
			_socketGroup.clear();
		};
		const char* socketName = zmqSocket->GetSocketName();
		auto it = _socketGroup.find(socketName);
		if(it != _socketGroup.end()){
			_socketGroup.clear();
			return false;
		}
		_socketGroup[socketName] = zmqSocket;	

	}


	return true;
}


bool ServerSocket::Loop()
{
	char buffer[SOCKET_BUFFER_SIZE];
	while(true)
	{
		for(auto it :_socketGroup)
		{
			if(it.second->Recv(buffer)){
				_messageManage.MessageDel(buffer,it.first.c_str());
			};	
		}

		usleep(200);
	}

	return true;
}

void  ZmqSocket::Send(const char *buffer,int size){
	zmq_send(_socket,buffer,size,0);
}

void ServerSocket::SendToAll(const ProtoBuffMessage& message){
	std::string buffer;
	auto size = _messageManage.decode(buffer,message);
	for(auto it : _socketGroup)
	{
		it.second->Send(buffer.c_str(),size);	
	}
}
void ServerSocket::Send(const char*objName,const ProtoBuffMessage& message)
{
		if(HF::CharIsNull(objName)){
			return ;
		}
		auto it = _socketGroup.find(objName);
		if(it != _socketGroup.end()){
		std::string buffer;
		auto size = _messageManage.decode(buffer,message);
			it->second->Send(buffer.c_str(),size);	
		}
}
