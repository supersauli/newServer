#include "sSctpPool.h"
#include "sSctpPthread.h"
void *sctpThreadFunc ( void *arg)
{

	((sPthread*)arg)->run();


	return NULL;
};

void sSctpPool::initPool(DWORD dwPthreadTimes)
{
	for(DWORD i=0;i<dwPthreadTimes;i++)
	{
		sSctpPthread *pth = _sctpPool.createNewPthread<sSctpPthread >(sctpThreadFunc);
		if(pth == NULL)
		{
			printf("crateNewPthread error\n");	
		}
		_sctpPool.addPthreadToPool(pth);
		usleep(5000);
	}

}


void sSctpPool::stcpNewClient(DWORD dwSocket)
{
	_dwTimes = _dwTimes%_sctpPool.getPthreadSize();
	
	sSctpPthread *pthread = (sSctpPthread*)_sctpPool.getPhteadByIndex(_dwTimes);
	if(pthread != NULL)
	{
		pthread->addClient(dwSocket);
	}
	_dwTimes++;
}
