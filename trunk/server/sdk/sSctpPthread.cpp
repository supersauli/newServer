#include "sSctpPthread.h"
#include "UserTest.h"
void sSctpPthread::run()
{
	init();
	struct epoll_event* events = new epoll_event[1000];
	int eventTimes = 0;
	while(true)
	{
		bzero(events,1000);
		eventTimes = epoll_wait(_efd,events,1000,0);
		if(eventTimes == -1)
			continue;
		//_mutex.lock();
		for(int i = 0; i< eventTimes;i++)
		{

			if((events[i].events & EPOLLERR) ||
					(events[i].events &EPOLLHUP))
			{
				struct epoll_event ev; 
				close(((UserTest*)(events[i].data.ptr))->getSocket());   
				epoll_ctl(_efd,EPOLL_CTL_DEL,((UserTest*)(events[i].data.ptr))->getSocket(),&ev);
				delete((UserTest*)events[i].data.ptr);
				printf("close socket pid %ld \n",pthread_self());
			}
			else if(events[i].events &EPOLLIN)
			{
				//有事件可读
				char buf[1024];
				bzero(&buf,sizeof(buf));
				int ret = sctp_recvmsg(((UserTest*)(events[i].data.ptr))->getSocket(),buf,sizeof(buf),(struct sockaddr *)NULL,0,(struct sctp_sndrcvinfo *)NULL,(int *)NULL);
				if(ret == 0 )
				{

					struct epoll_event ev;
					ev.data.fd = ((UserTest*)(events[i].data.ptr))->getSocket();
					ev.events = EPOLLOUT;
					int fd = ev.data.fd;
					epoll_ctl(_efd,EPOLL_CTL_DEL,ev.data.fd,&ev);
					close(ev.data.fd);
					((UserTest*)events[i].data.ptr)->end = true;
				//	delete((UserTest*)events[i].data.ptr);
					printf("recv message error close socket id %d pid %ld \n",fd,pthread_self());

				}
				else
				{
					((UserTest*)(events[i].data.ptr))->dealMsg(buf);
				}

				//printf(" this **  buf is %s  process id %ld\n",buf,pthread_self());
			}	
		//	else if(events[i].events & EPOLLOUT)
		//	{
				//printf("can write \n");	
			
		//	}


		}   
		//_mutex.unLock();
		usleep(100);
	}   
}
void sSctpPthread::sendCmd(DWORD dwSocket,char *buf)
{
	if(sctp_sendmsg(dwSocket,buf,strlen(buf),0,0,0,0,0,0,0) <=0)
	{
		printf("send error \n"); 

	};
}

bool sSctpPthread::init()
{
	_efd = epoll_create(100000);
	if(_efd == -1)
		return false;
	return true;
}

void sSctpPthread::addClient(DWORD dwSocket)
{
	//printf("Awaiting a new connection  process %d \n",getpid());
	//int connSock = ::accept( dwSocket, (struct sockaddr *)NULL, (socklen_t *)NULL );
	//fcntl(connSock,F_SETFL,O_NONBLOCK);
	//_mutex.lock();
	//printf("Awaiting a new connection  process %d \n",getpid());
	fcntl(dwSocket,F_SETFL,O_NONBLOCK);
	struct epoll_event ev;
	ev.data.ptr = new UserTest(dwSocket,this);
	((UserTest*)ev.data.ptr)->end = false;
	ev.events = EPOLLIN | EPOLLET | EPOLLOUT;
	int s = epoll_ctl(_efd,EPOLL_CTL_ADD,dwSocket,&ev);
	if(s == -1)
		return;
	fcntl(dwSocket,F_SETFL,O_NONBLOCK);
	//_mutex.unLock();

}


