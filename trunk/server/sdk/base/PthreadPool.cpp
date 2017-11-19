#include "PthreadPool.h"
bool PthreadPool::AddPthreadToPool(Pthread * pthread)
{
	PTHREADIT it = _pthreadPool.find(_poolIndex);

	if(it != _pthreadPool.end())
			return false;

	_pthreadPool.insert(std::make_pair(_poolIndex,pthread));
	_poolIndex++;

	return true;
}
Pthread* PthreadPool::GetPhteadByIndex(DWORD dwIndex)
{
	PTHREADIT it = _pthreadPool.find(dwIndex);
	if(it != _pthreadPool.end())
	{
		return it->second; 
	}
	return NULL;
}
