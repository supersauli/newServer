#include "sSctpPool.h"
#include "sSctpPthread.h"
void *sctpThreadFunc ( void *arg)
{

	((sPthread*)arg)->Init();
	((sPthread*)arg)->Run();
	return nullptr;
};

void sSctpPool::InitPool()
{
	for(DWORD i=0;i<_pthreadMax;i++)
	{
		sSctpPthread *pth = _sctpPool.CreateNewPthread<sSctpPthread>(sctpThreadFunc);
		if(pth == nullptr){
			printf("crateNewPthread error\n");	
		}
		_sctpPool.AddPthreadToPool(pth);
		usleep(5000);
	}

}


void sSctpPool::NewClient(DWORD dwSocket)
{
	_pthreadIndex =_pthreadIndex%_sctpPool.GetPthreadSize();
	sSctpPthread *pthread = (sSctpPthread*)_sctpPool.GetPhteadByIndex(_pthreadIndex);
	if(pthread != NULL){
		pthread->AddClient(dwSocket);
	}
	++_pthreadIndex;
}
