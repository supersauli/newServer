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
	typedef std::function<void(DWORD fd)> CallBack;
	public:
		bool 	Init();
		bool    Bind();
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

		void	SetAddClient(CallBack cb){_addClient = cb;}
		void	SetBackLog(int backlog){_backlog = backlog;}
		void	SetIpAddress(const char* ipAddress){_ipAddress = ipAddress;}	
		void    SetPort(DWORD port){_port = port;}
	private:
		std::string _ipAddress;
		DWORD       _port;
		struct sockaddr_in _servaddr;
		int _backlog{DEFAULT_BACKLOG};
		CallBack _addClient;
		sEpoll _epoll;


};



#endif
