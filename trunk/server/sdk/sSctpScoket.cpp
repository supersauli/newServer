#include "sSctpScoket.h"
bool sSctpScoket::initSocket()
{
	_sSockListen = socket(AF_INET,SOCK_STREAM,IPPROTO_SCTP);
	if(_sSockListen == -1)
		return false;

	fcntl(_sSockListen,F_SETFL,O_NONBLOCK);
	_efd = epoll_create(100000);
	if(_efd == -1)
		return false; 
	return true;
}
bool sSctpScoket::bind(DWORD dwPort)
{
	bzero((void *)&_servaddr,sizeof(_servaddr));

	_servaddr.sin_family = AF_INET;
	_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	_servaddr.sin_port = htons(dwPort);

	_ret = ::bind(_sSockListen,(struct sockaddr*)&_servaddr,sizeof(_servaddr));
	if(_ret<0)
		return false;
	
//	struct sctp_initmsg initmsg;
//	memset( &initmsg, 0, sizeof(initmsg) );
//	initmsg.sinit_num_ostreams = 500;
//	initmsg.sinit_max_instreams = 500;
//	initmsg.sinit_max_attempts = 400;
//	ret = setsockopt( _connSock, IPPROTO_SCTP, SCTP_INITMSG, 
//			&initmsg, sizeof(initmsg) );
//
//第二个参数不确定要填多大
	listen(_sSockListen,2000);
	printf("accetp new connection \n");
	bzero(_buf,sizeof(_buf));	
	return true;
}

void sSctpScoket::stcpAccept()
{
	struct epoll_event* events = new epoll_event[1000];
//	_connSock = ::accept(_sSockListen,(struct sockaddr*)NULL,(socklen_t *)NULL);	
//
	struct epoll_event ev;
	ev.data.fd = _sSockListen; 
	ev.events = EPOLLIN ;
	int s = epoll_ctl(_efd,EPOLL_CTL_ADD,_sSockListen,&ev);   
	if(s == -1) 
		return;
	
	int eventTimes = 0;
	while(true)
	{

		bzero(events,1000);
		eventTimes = epoll_wait(_efd,events,1000,TimeOut);
		if(eventTimes == -1)
			continue;
		for(int i =0;i<eventTimes;i++)
		{
			if(_sSockListen == events[i].data.fd)   
			{ //新连接

				int connSock = ::accept(_sSockListen, (struct sockaddr *)NULL, (socklen_t *)NULL);
				stcpNewClient(connSock);
	//			printf("Awaiting a new connection  process %d \n",getpid());
	//			int connSock = ::accept( _sSockListen, (struct sockaddr *)NULL, (socklen_t *)NULL );
	//			fcntl(connSock,F_SETFL,O_NONBLOCK);
	//			struct epoll_event ev; 
	//			ev.data.fd = connSock ;
	//			ev.events = EPOLLIN ;
	//			int s = epoll_ctl(_efd,EPOLL_CTL_ADD,connSock,&ev);
	//			if(s == -1)
	//				return;
			}	

		}
	}

	close(_sSockListen);
}
