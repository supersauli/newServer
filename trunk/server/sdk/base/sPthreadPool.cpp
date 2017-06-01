#include "sPthreadPool.h"
bool sPthreadPool::AddPthreadToPool(sPthread * pthread)
{
	PTHREADIT it = _pthreadPool.find(_poolIndex);

	if(it != _pthreadPool.end())
			return false;

	_pthreadPool.insert(std::make_pair(_poolIndex,pthread));
	_poolIndex++;

	return true;
}
sPthread* sPthreadPool::GetPhteadByIndex(DWORD dwIndex)
{
	PTHREADIT it = _pthreadPool.find(dwIndex);
	if(it != _pthreadPool.end())
	{
		return it->second; 
	}
	return NULL;
}
