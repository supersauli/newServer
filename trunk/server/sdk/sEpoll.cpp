#include "sEpoll.h"

bool sEpoll::epollInit(int maxfdSize)
{
//	_epollfd = epoll_create(maxfdSize);
//	if(_epollfd == -1)
//		return false;
//
//	_events  = new epoll_event[maxfdSize];
//	if(_events == NULL)
//		 return false;
//	_maxfdSize = maxfdSize;
	return true;
}

/**
 * @brief 增加一个事件
 *
 * @param epollfd
 * @param event
 * @param fd
 *
 * @return 
 */
bool sEpoll::epollAddEvent(int epollfd,int event,int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd ;
	//不要弄成边沿触发 会有收到消息不全的风险
    ev.events = event ;
	return  epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev);   

}

/**
 * @brief 删除一个事件
 *
 * @param epollfd
 * @param event
 * @param fd
 *
 * @return 
 */
bool sEpoll::epollDelEvent(int epollfd,int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	//不要弄成边沿触发 会有收到消息不全的风险
	return  epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,&ev);   
}


bool  sEpoll::epollChangeEvent(int epollfd,int event,int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd ;
	//不要弄成边沿触发 会有收到消息不全的风险
    ev.events = event ;
	return  epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&ev);   
}
