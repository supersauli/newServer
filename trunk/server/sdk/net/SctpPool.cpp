#include "SctpPool.h"
#include "SctpPthread.h"
using namespace sdk;
void *SctpThreadFunc ( void *arg)
{

	static_cast<Pthread*>(arg)->Init();
	static_cast<Pthread*>(arg)->Run();
	return nullptr;
};

void SctpPool::InitPool()
{
	for(DWORD i=0;i<_pthreadMax;i++)
	{
		auto pth = _sctpPthreadPool.CreateNewPthread<SctpPthread>(SctpThreadFunc);
		if(pth == nullptr){
			printf("crateNewPthread error\n");	
		}
		_sctpPthreadPool.AddPthreadToPool(pth);
		usleep(5000);
	}

}


void SctpPool::NewClient(DWORD dwSocket)
{
	_pthreadIndex =_pthreadIndex%_sctpPthreadPool.GetPthreadSize();
	auto pthread = static_cast<SctpPthread*>(_sctpPthreadPool.GetPhteadByIndex(_pthreadIndex));
	if(pthread != NULL){
		pthread->AddClient(dwSocket);
	}
	++_pthreadIndex;
}
