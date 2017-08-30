#ifndef __LOGIN_MESSAGE_H__
#define __LOGIN_MESSAGE_H__
#include "../sdk/sdk.h"
#include "../proto/ProtobufList.h"
using namespace sdk;
class LoginMessage{

	public :
		bool Init(ServerSocket& socket);
		void InitMessage();
		void InitMessageCallBack();

		void NewGateway(void*message,const char*name);





	private:
		ServerSocket* _socket;

};







#endif
