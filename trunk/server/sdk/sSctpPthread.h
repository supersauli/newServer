#ifndef _SSCTPPTHREAD_H__
#define _SSCTPPTHREAD_H__
#include "sPthread.h"
#include "sSctpScoket.h"
class sSctpPthread :public  sPthread
{
	public:
		sSctpPthread(pthread_func pFunc):sPthread(pFunc){};
		virtual void run();
		virtual bool init();
		void addClient(DWORD dwSocket);
		void sendCmd(DWORD dwSocket,char *buf);
	private:
		 int _efd;




};


#endif
