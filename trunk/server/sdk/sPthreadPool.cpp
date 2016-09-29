#include "sPthreadPool.h"
//#include "sSctpPthread.h"
//void* func (void *arg)
//{
//     printf("phtead create++++++++++++++ %s \n",arg);
//	 return NULL;
//}
//template <typename T>
//T *sPthreadPool::createNewPthread(pthread_func  func)
//{
//	T *pth = new T(func);
//	return pth;	
//}
bool sPthreadPool::addPthreadToPool(sPthread * pthread)
{
	PTHREADIT it = _pthreadPool.find(_poolIndex);

	if(it != _pthreadPool.end())
			return false;

	_pthreadPool.insert(std::make_pair(_poolIndex,pthread));
	_poolIndex++;

	return true;
}
sPthread* sPthreadPool::getPhteadByIndex(DWORD dwIndex)
{
	PTHREADIT it = _pthreadPool.find(dwIndex);
	if(it != _pthreadPool.end())
	{
		return it->second; 
	}
	return NULL;
}
