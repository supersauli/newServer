#include "Epoll.h"
using namespace sdk;
bool Epoll::Init(int maxfdSize)
{
	_epollfd = epoll_create(maxfdSize);
	if(_epollfd == -1)
		return false;
	_maxfdSize = maxfdSize;
	return true;
}

/**
 * @brief 增加一个事件
 *
 * @param event
 * @param fd
 *
 * @return 
 */
bool Epoll::AddEvent(int fd,int event)
{
	struct epoll_event ev;
	ev.data.fd = fd ;
	//不要弄成边沿触发 会有收到消息不全的风险
    ev.events = event ;
	return  epoll_ctl(_epollfd,EPOLL_CTL_ADD,fd,&ev);   

}

/**
 * @brief 删除一个事件
 *
 * @param event
 * @param fd
 *
 * @return 
 */
bool Epoll::DelEvent(int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	//不要弄成边沿触发 会有收到消息不全的风险
	return  epoll_ctl(_epollfd,EPOLL_CTL_DEL,fd,&ev);   
}


bool  Epoll::UpdateEvent(int fd,int event)
{
	struct epoll_event ev;
	ev.data.fd = fd ;
	//不要弄成边沿触发 会有收到消息不全的风险
    ev.events = event ;
	return  epoll_ctl(_epollfd,EPOLL_CTL_MOD,fd,&ev);   
}
bool Epoll::Loop()
{
	struct epoll_event* events = new epoll_event[_maxEvents];
	

	while(true)
	{
		int eventTimes = epoll_wait(_epollfd,events,_maxEvents,_timeOut);		
		if(eventTimes == -1){
			continue;
		}
		for(int i = 0;i<eventTimes;i++)
		{
			if(_listenSocket == events[i].data.fd){
				if(_newClientCB !=nullptr){
					_newClientCB(_listenSocket);
				}
			}

			else if(events[i].events&(EPOLLERR|EPOLLHUP)){
				if(_closeCB !=nullptr){
				_closeCB(events[i].data.fd);
				}
			}

			else if(events[i].events& EPOLLIN){
				if(_readCB != nullptr){
					_readCB(events[i].data.fd);
				}
			}
		}
	}
	return true;
}

