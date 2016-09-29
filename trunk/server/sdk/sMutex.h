#ifndef _SMUTEX_H_
#define _SMUTEX_H_
#include <pthread.h>
class sMutex{
	public:
		sMutex();
		~sMutex();
		void lock();
		void unLock();

	private:

		pthread_mutex_t _mutex;




};







#endif
