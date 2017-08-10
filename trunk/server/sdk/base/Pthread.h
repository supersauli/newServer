#ifndef _SPTHREAD_H__
#define _SPTHREAD_H__
#include <pthread.h>
#include <stdio.h>
#include "Mutex.h"
typedef void* (*pthread_func)(void *arg);
class Pthread{
	public:
			Pthread(pthread_func pFunc)
			{
				int error = pthread_create(&_ntid,NULL,pFunc,this);
				if(error != 0)
				{
					printf("pthrad Create Error \n");	
				}

			}
		virtual void Run(){};
		virtual bool Init(){return true;};
	protected:
		 Mutex _mutex;
	private:
		pthread_t _ntid;

};
#endif
