#ifndef _SSCTPPTHREAD_H__
#define _SSCTPPTHREAD_H__
#include "sPthread.h"
#include "sSctpScoket.h"
class sSctpPthread :public  sPthread
{
	public:
		sSctpPthread(pthread_func pFunc):sPthread(pFunc){};
		virtual void Run();
		virtual bool Init();
		void AddClient(DWORD dwSocket);
		void SendCmd(DWORD dwSocket,char *buf);
		void Read(int fd);
		
	private:
		sEpoll _epoll;




};


#endif
