#ifndef _SSCTPPOOL_H__
#define _SSCTPPOOL_H__
#include "SctpSocket.h"
#include "../base/PthreadPool.h"
namespace sdk{
	class SctpPool
	{
		public:
			SctpPool(){
			};

			virtual void NewClient(DWORD dwSocket);
			void InitPool();
			void SetPthreadMax(int pthreadMax){_pthreadMax = pthreadMax;}
		private:
			PthreadPool _sctpPthreadPool;
			DWORD _pthreadIndex{0};
			DWORD _pthreadMax{1};


	};
};

#endif
