#include "sSctpPthread.h"
#include "UserTest.h"

bool sSctpPthread::Init()
{
	_epoll.Init();	
	_epoll.SetReadCB(std::bind(&sSctpPthread::Read,this,std::placeholders::_1));
	return true;
}

void sSctpPthread::Read(int fd)
{
	char buf[1024]={};
	int ret = sctp_recvmsg(fd,buf,sizeof(buf),(struct sockaddr *)NULL,0,(struct sctp_sndrcvinfo *)NULL,(int *)NULL);
	if(ret == 0 )
	{
		printf("error fd = %d\n",fd);	
		_epoll.DelEvent(fd);
		return;
	}
	//_message.ecode(buf);
	_epoll.UpdateEvent(fd,EPOLLIN | EPOLLET | EPOLLOUT);
}

void sSctpPthread::Run()
{
	_epoll.Loop();
}

void sSctpPthread::SendCmd(DWORD dwSocket,char *buf)
{
//	char buf[1024];
	//_message.decode(buff,mproto)


	if(sctp_sendmsg(dwSocket,buf,strlen(buf),0,0,0,0,0,0,0) <=0)
	{
		printf("send error \n"); 
	};
}


void sSctpPthread::AddClient(DWORD dwSocket)
{
	fcntl(dwSocket,F_SETFL,O_NONBLOCK);
	_epoll.AddEvent(dwSocket,EPOLLIN | EPOLLET | EPOLLOUT);

	//struct epoll_event ev;
	//ev.data.ptr = new UserTest(dwSocket,this);
	//((UserTest*)ev.data.ptr)->end = false;
	//ev.events = EPOLLIN | EPOLLET | EPOLLOUT;
	//int s = epoll_ctl(_efd,EPOLL_CTL_ADD,dwSocket,&ev);
	//if(s == -1)
	//	return;

}


