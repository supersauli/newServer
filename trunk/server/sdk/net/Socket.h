#ifndef __S_SOCKET_H__
#define __S_SOCKET_H__
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>
#include <zmq.h>
#include "sdk/net/Protobuf.h"
#define MSG google::protobuf::Message
namespace sdk{
	class Socket
	{

		public:
			bool Init(const std::string& ipPort);
			void SetOverTime(int time){
				_overTime = time;
			}

			void sendMessage(const MSG& message);

		private:
			std::string _ipPort;
			void *_socket;
			int _overTime{5000};
			void *_ctx;
			ProtobufManage _protobufManage;







	};

};







#endif
