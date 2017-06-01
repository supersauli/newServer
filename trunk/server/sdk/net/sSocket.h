#ifndef __S_SOCKET_H__
#define __S_SOCKET_H__
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>
#include <zmq.h>
#include "sdk/sProtobuf.h"
#define MSG google::protobuf::Message

class sSocket
{
	
pbulic:
	bool Init(const std::string& ipPort);
	void SetOverTime(int time){
		_OverTime = time;
	}

	void sendMessage(const MSG& message);

pirvate:
	std::string _ipPort;
	void *_socket;
	int _overTime{5000};
	void *_ctx;
	ProtobufManage _protobufManage;







}









#endif
