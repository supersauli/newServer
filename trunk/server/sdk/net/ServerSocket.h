#ifndef __SERVER_SOCKET_H__
#define __SERVER_SOCKET_H__
#include <zmq.h>
#include <iostream>
#include <string>
#include "sdk/base/LogManager.h"
#include "sdk/base/JsonManager.h"
#include "sdk/net/Protobuf.h"

namespace sdk{
	enum class SocketType
	{
		SOCKET_TYPE_NONE=-1,
		/**
		 * @brief 请求/应答模式   client send>recv>send 进入mute状态后:阻塞
		 */
		SOCKET_TYPE_REQ,
		/**
		 * @brief 请求/应答模式  server recv>send>recv 进入mute状态后:阻塞
		 */
		SOCKET_TYPE_REP,
  		/**
		 * @brief 请求/应答模式  高级 进入mute状态后：阻塞
		 */
		SOCKET_TYPE_DEALER,
		SOCKET_TYPE_ROUTER,
		/**
		 * @brief 发布/订阅模式 发送方 不能调用 recv 进入mute状态后:丢弃消息
		 */
		SOCKET_TYPE_PUB,

		/**
		 * @brief 接收/订阅模式 接收方 不能调用 send 进入mute状态后:丢弃消息
		 */
		SOCKET_TYPE_SUB,
		
	};

	class ServerSocket :public ProtobufManage
	{
		public:
			bool Init(Json::Value& config);
			bool Run();
			void SendMessage(const ProtoBuffMessage& message);
			SocketType GetSocketType();	
			~ServerSocket();
		private:
			/**
			 * @brief 转换成zmq的类型
			 *
			 * @param type
			 *
			 * @return 
			 */
			int SwitchSocketType(const SocketType &type);
			SocketType _type{SocketType::SOCKET_TYPE_NONE};
			std::string _address;
			int _timeOut{5000};
			void *_socket{nullptr};
			void *_ctx{nullptr};
			//sdk::LogManager _log;
			sdk::ProtobufManage _message;
	};

}
#endif

