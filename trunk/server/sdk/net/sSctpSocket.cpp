#include "sSctpSocket.h"
#include <arpa/inet.h>
bool sSctpSocket::Init()
{
	if(!_epoll.Init()){
		return false;
	};
//	_epoll.SetReadCB(std::bind(&sSctpSocket::Read,this,std::placeholders::_1));
	return true;
}
bool sSctpSocket::Bind()
{
	 _fd = socket(AF_INET,SOCK_STREAM,IPPROTO_SCTP);
	if(_fd == -1){
		return false;
	}
	
	_epoll.SetListenSocket(_fd);
	_epoll.AddEvent(_fd,EPOLLIN|EPOLLET);
	bzero((void *)&_servaddr,sizeof(_servaddr));
	_servaddr.sin_family = AF_INET;
	//_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);// 所有ip
	_servaddr.sin_addr.s_addr =inet_addr(_ipAddress.c_str());
	_servaddr.sin_port = htons(_port);

	int ret = ::bind(_fd,(struct sockaddr*)&_servaddr,sizeof(_servaddr));
	if(ret<0){
		return false;
	}
	
//	struct sctp_initmsg initmsg;
//	memset( &initmsg, 0, sizeof(initmsg) );
//	initmsg.sinit_num_ostreams = 500;
//	initmsg.sinit_max_instreams = 500;
//	initmsg.sinit_max_attempts = 400;
//	ret = setsockopt( _connSock, IPPROTO_SCTP, SCTP_INITMSG, 
//			&initmsg, sizeof(initmsg) );
//
	listen(_fd,_backlog);
	_epoll.SetNewClientCB(std::bind(&sSctpSocket::Accept,this,std::placeholders::_1));
	printf("accetp new connection \n");
	return true;
}

void sSctpSocket::SetNoBlock(int fd){
	fcntl(fd,F_SETFL,O_NONBLOCK);
}

void sSctpSocket::Accept(int fd)
{
	int newfd = ::accept(fd, (struct sockaddr *)NULL, (socklen_t *)NULL);
	if(newfd < 0){
		printf("error");
		return ;
	}

	if(_addClient != nullptr){
		_addClient(newfd);
	}
	printf("new client \n");
}
void sSctpSocket::Read(int fd)
{


}

void sSctpSocket::Write(int fd,const char*msg)
{
	sctp_send(fd,msg,strlen(msg),NULL,0);

}

void sSctpSocket::Loop()
{
	_epoll.Loop();
}

bool sSctpSocket::Connect()
{
	 _fd = socket(AF_INET,SOCK_STREAM,IPPROTO_SCTP);
	if(_fd == -1){
		return false;
	}
	bzero((void *)&_servaddr,sizeof(_servaddr));
	_servaddr.sin_family = AF_INET;
	_servaddr.sin_addr.s_addr =inet_addr(_ipAddress.c_str());
	_servaddr.sin_port = htons(_port);

	int rt = sctp_connectx(_fd, (struct sockaddr*)&_servaddr, 1,NULL);
	if(rt<0){
		return false;
	}

	return true;
}
void  sSctpSocket::Close(int fd)
{
	close(fd);
}
