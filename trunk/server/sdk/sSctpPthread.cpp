#include "sSctpPthread.h"
#include "UserTest.h"
void sSctpPthread::Run()
{
	_epoll.Loop();
}

void sSctpPthread::SendCmd(DWORD dwSocket,char *buf)
{
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


