#include "sSctpScoket.h"
#include <arpa/inet.h>
bool sSctpScoket::Init()
{
	if(!_epoll.Init()){
		return false;
	};

	_epoll.SetNewClientCB(std::bind(&sSctpScoket::Accept,this,std::placeholders::_1));
//	_epoll.SetReadCB(std::bind(&sSctpScoket::Read,this,std::placeholders::_1));
	return true;
}
bool sSctpScoket::Bind()
{
	int fd = socket(AF_INET,SOCK_STREAM,IPPROTO_SCTP);
	if(fd == -1){
		return false;
	}
	
	_epoll.SetListenSocket(fd);
	_epoll.AddEvent(fd,EPOLLIN|EPOLLET);
	bzero((void *)&_servaddr,sizeof(_servaddr));
	_servaddr.sin_family = AF_INET;
	//_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);// 所有ip
	_servaddr.sin_addr.s_addr =inet_addr(_ipAddress.c_str());
	_servaddr.sin_port = htons(_port);

	int ret = ::bind(fd,(struct sockaddr*)&_servaddr,sizeof(_servaddr));
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
	listen(fd,_backlog);
	printf("accetp new connection \n");
	return true;
}

void sSctpScoket::SetNoBlock(int fd){
	fcntl(fd,F_SETFL,O_NONBLOCK);
}

void sSctpScoket::Accept(int fd)
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
void sSctpScoket::Read(int fd)
{


}

void sSctpScoket::Write(int fd)
{


}

void sSctpScoket::Loop()
{
	_epoll.Loop();
}
