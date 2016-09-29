#ifndef _SPTHREAD_H__
#define _SPTHREAD_H__
#include <pthread.h>
#include <stdio.h>
#include "sMutex.h"
typedef void* (*pthread_func)(void *arg);
class sPthread{
	public:
			sPthread(pthread_func pFunc)
			{
				int error = pthread_create(&_ntid,NULL,pFunc,this);
				if(error != 0)
				{
					printf("pthrad Create Error \n");	
				}

			}
		virtual void run(){};
		virtual bool init(){return true;};
	protected:
		 sMutex _mutex;
	private:
		pthread_t _ntid;

};
#endif
