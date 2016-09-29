#ifndef _SSCTPPOOL_H__
#define _SSCTPPOOL_H__
#include "sSctpScoket.h"
#include "sPthreadPool.h"
class sSctpPool :public sSctpScoket
{
	public:
		sSctpPool(){
			_dwTimes = 0;	
		};

	 virtual void stcpNewClient(DWORD dwSocket);
	 void initPool(DWORD dwPthreadTimes);
	private:
	 sPthreadPool _sctpPool;
	 DWORD _dwTimes;


};


#endif
