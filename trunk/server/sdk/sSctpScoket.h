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
#include "sEpoll.h"
static const int TimeOut = -1;
#define DEFAULT_BACKLOG 24
class sSctpScoket
{
	public:
		bool 	Init();
		bool    Bind(DWORD dwPort);
		virtual void    Accept(int fd);
		virtual void	Read(int fd);
		virtual void	Write(int fd);

		void    SetNoBlock(int fd);
		void	Loop();
		
		template<typename CB>
		void SetReadCallBack(CB cb){
			_epoll.SetReadCB(std::forward<CB>(cb));
		}
		template<typename CB>
		void SetCloseCB(CB cb){
			_epoll.SetCloseCB(std::forward<CB>(cb));
		}
		template<typename CB>
		void SetAccetp(CB cb){
			_epoll.SetNewClientCB(std::forward<CB>(cb));
		}

		virtual void stcpNewClient(DWORD dwSocket) = 0;

		void	SetBackLog(int backlog){
			_backlog = backlog;
		}
		
	private:
		struct sockaddr_in _servaddr;
		int _backlog{DEFAULT_BACKLOG};
		sEpoll _epoll;


};



#endif
