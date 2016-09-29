#include "sMutex.h"

sMutex::sMutex()
{
	pthread_mutex_init(&_mutex,NULL);
}

sMutex:: ~sMutex()
{
	pthread_mutex_destroy(&_mutex);
}

void sMutex::lock()
{
	pthread_mutex_lock(&_mutex);	
}

void sMutex::unLock()
{
	pthread_mutex_unlock(&_mutex);
}
