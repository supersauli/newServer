#ifndef _SSCTPPTHREAD_H__
#define _SSCTPPTHREAD_H__
#include "../base/Pthread.h"
#include "SctpSocket.h"
#include "Protobuf.h"
namespace sdk{
	class SctpPthread :public  Pthread
	{
		public:
			SctpPthread(pthread_func pFunc):Pthread(pFunc){};
			virtual void Run();
			virtual bool Init();
			void AddClient(DWORD dwSocket);
			void SendCmd(DWORD dwSocket,char *buf);
			void Read(int fd);

		private:
			Epoll _epoll;
			ProtobufManage _message;




	};
};

#endif
