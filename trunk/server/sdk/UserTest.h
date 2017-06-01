#ifndef _USERTEXT_H__
#define _USERTEXT_H__
#include <string>
#include <stdio.h>
#include "./base/sDefine.h"
#include "./net/sSctpPthread.h"
#include "./base/sPthread.h"
class UserTest
{
	public:
		UserTest(DWORD dwSocket,sSctpPthread* pth){
			_dwSocket = dwSocket;
			_sctpPth = pth;
		};
		void dealMsg(char *arg);
		DWORD getSocket(){return _dwSocket;};
		bool SendCmd(DWORD dwSocket,char *buf);
		bool end;
	private:
		DWORD _dwSocket;
		sSctpPthread* _sctpPth;
	






};
#endif
