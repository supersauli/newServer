#ifndef _USERTEXT_H__
#define _USERTEXT_H__
#include <string>
#include <stdio.h>
#include "./base/Define.h"
#include "./net/SctpPthread.h"
#include "./base/Pthread.h"
using namespace sdk;
namespace sdk{
class UserTest
{
	public:
		UserTest(DWORD dwSocket,SctpPthread* pth){
			_dwSocket = dwSocket;
			_sctpPth = pth;
		};
		void dealMsg(char *arg);
		DWORD getSocket(){return _dwSocket;};
		bool SendCmd(DWORD dwSocket,char *buf);
		bool end;
	private:
		DWORD _dwSocket;
		SctpPthread* _sctpPth;
	






};
}
#endif
