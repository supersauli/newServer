#ifndef __SSERVER_H__
#define __SSERVER_H__
#include "SctpPool.h"
namespace sdk{
	class Server
	{
		public:
			bool Init();
			bool LoadConfig(const char* fileName);
			bool Loop();
			void SetServerName(const char* serverName){
				_serverName = serverName;
			}
			const char* GetServerName(){return _serverName.c_str();}
		private:
			SctpPool _pool;
			SctpSocket _socket;
			std::string _serverName;

	};
};



#endif
