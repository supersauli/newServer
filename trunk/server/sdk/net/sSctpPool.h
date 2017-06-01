#ifndef _SSCTPPOOL_H__
#define _SSCTPPOOL_H__
#include "sSctpSocket.h"
#include "../base/sPthreadPool.h"
class sSctpPool
{
	public:
		sSctpPool(){
		};

	 virtual void NewClient(DWORD dwSocket);
	 void InitPool();
	 void SetPthreadMax(int pthreadMax){_pthreadMax = pthreadMax;}
	private:
	 sPthreadPool _sctpPool;
	 DWORD _pthreadIndex{0};
	 DWORD _pthreadMax{1};


};


#endif
