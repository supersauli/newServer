#ifndef __SERVER_SOCKET_H__
#define __SERVER_SOCKET_H__
#include <zmq.h>
#include <iostream>
#include <string>
#include "sdk/base/LogManager.h"
#include "sdk/base/JsonManager.h"

namespace sdk{
	enum class SocketType
	{
		SOCKET_TYPE_NONE=-1,
		SOCKET_TYPE_ROUTE,
	};



	class ServerSocket
	{
		public:
			bool Init(Json::Document& info);
			bool Run();

		private:
			SocketType _type{SocketType::SOCKET_TYPE_NONE};
			std::string _address;
			int _timeOut{5000};
			void *_socket;
	};

	static sdk::LogManager _log;
}
#endif

