#ifndef _SSTCPSCOKET_H__
#define _SSTCPSCOKET_H__
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/sctp.h>
#include <iostream>
#include "sDefine.h"
#include <sys/epoll.h>
#include <fcntl.h>
static const int TimeOut = -1;
class sSctpScoket
{
	public:
		bool 	initSocket();
		bool    bind(DWORD dwPort);
		void    stcpAccept();
		virtual void stcpNewClient(DWORD dwSocket) = 0;
		
	private:
		struct sockaddr_in _servaddr;
		int _sSockListen;
		//int _connSock;
		int _ret;
		int _efd;
		char _buf[1024];



};



#endif
