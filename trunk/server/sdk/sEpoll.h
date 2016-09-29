#ifndef _SEPOLL_H__
#define _SEPOLL_H__
#include <sys/epoll.h>
#include <stdio.h>
#include "sDefine.h"




class sEpoll
{
	public:
		enum 
		{
			EPOLL_NONE   , //不处理
			EPOLL_NEWCLIENT,//新连接	
			EPOLL_RECV,//收到数据
			EPOLL_SEND,//有数据发送
		};



		/**
		 * @brief 初始化epoll
		 *
		 * @param maxfdSize
		 *
		 * @return 
		 */
		bool epollInit(int maxfdSize);
		/**
		 * @brief 增加一个事件
		 *
		 * @param epollfd epoll句柄
		 * @param event
		 * @param connfd   文件描述符
		 */
		bool epollAddEvent(int epollfd,int event,int fd); 
		/**
		 * @brief 删除一个事件
		 *
		 * @param epollfd
		 * @param event
		 * @param connfd
		 */
		bool epollDelEvent(int epollfd,int fd);
		/**
		 * @brief 修改一个事件
		 *
		 * @param epollfd
		 * @param event
		 * @param connfd
		 */
		bool epollChangeEvent(int epollfd,int event,int connfd);





//	private:
//
//		 int _epollfd;//epoll句柄
//		 struct epoll_event _ev;
//		 struct epoll_event *_events;
//		 int _maxfdSize;
//

};




#endif
