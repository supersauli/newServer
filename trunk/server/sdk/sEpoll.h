#ifndef _SEPOLL_H__
#define _SEPOLL_H__
#include <sys/epoll.h>
#include <stdio.h>
#include <functional>
#include "sDefine.h"

#define DEFAULT_TIMEOUT_TIMES 1000
#define DEFAULT_MAX_EVENTS 10

typedef std::function<void(int)> EventCB;

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
		bool Init(int maxfdSize = DEFAULT_MAX_EVENTS);
		/**
		 * @brief 增加一个事件
		 *
		 * @param event
		 * @param connfd   文件描述符
		 */
		bool AddEvent(int fd,int event); 
		/**
		 * @brief 删除一个事件
		 *
		 * @param epollfd
		 * @param event
		 * @param connfd
		 */
		bool DelEvent(int fd);
		/**
		 * @brief 修改一个事件
		 *
		 * @param event
		 * @param connfd
		 */
		bool UpdateEvent(int event,int connfd);

		bool Loop();


		/**
		 * @brief 设置超时时间
		 *
		 * @param timeOut
		 */
		void SetTimeOut(int timeOut){
			_timeOut = timeOut;
		};

		/**
		 * @brief  设置最大事件数
		 *
		 * @param events
		 */
		void  SetMaxEvents(int maxEvents){
			_maxEvents = maxEvents ;
		};

		/**
		 * @brief 设置监听socket
		 *
		 * @param listenSocket
		 */
		void SetListenSocket(int listenSocket){
			_listenSocket = listenSocket;
		};	

		/**
		 * @brief  新连接回调
		 *
		 * @param func
		 */
		void SetNewClientCB(EventCB& cb ){
				_newClientCB = cb;
		}
		void SetNewClientCB(EventCB&& cb ){
				_newClientCB = cb;
		}
		/**
		 * @brief 有事件可读回调
		 *
		 * @param func
		 */
		void SetReadCB(EventCB& cb){
			_readCB = cb;
		}
		void SetReadCB(EventCB&& cb){
			_readCB = cb;
		}

		/**
		 * @brief 断开连接回调
		 *
		 * @param func
		 */
		void SetCloseCB(EventCB& cb){
			_closeCB = cb;
		}
		void SetCloseCB(EventCB&& cb){
			_closeCB = cb;
		
		}

	private:

		 int _epollfd;//epoll句柄
		 int _maxfdSize;
		 int _timeOut{DEFAULT_TIMEOUT_TIMES };
		 int _maxEvents{DEFAULT_MAX_EVENTS };
		 int _listenSocket{0};

		 EventCB _newClientCB,_readCB,_closeCB;



};




#endif
