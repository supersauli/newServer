#include "LoginServer.h"
#include "../sdk/sdk.h"
#include <assert.h>
#include "../proto/ProtobufList.h"
#include "LoginMessage.h"
using namespace sdk;
int old = -1;
void Info(void*message)
{
	//auto res  = static_cast<GateServer::UserLogin*>(message);
	////assert( res->dwid() - old == 1);
	//old = res->dwid();

	//std::cout<<res->dwid()<<std::endl;

	//LoginProto::Result msg;
	//msg.set_dwid( res->dwid());
	//msg.set_result(true);
	//globalSocket->SendMessage(msg);


}

void SendMessage(ServerSocket& socket )
{
	{
		LoginProto::Result ret;
		ret.set_dwid(1);
		ret.set_result(2);

		socket.Send("Gate1",ret);
	}
	{
		LoginProto::Result ret;
		ret.set_dwid(2);
		ret.set_result(2);

		socket.Send("Gate2",ret);
	}


}

int main()
{
	ServerSocket socket;
	Json::Document doc;
	JsonManager::ParseFile("/home/sauli/server/cfg/servercfg/ipcfg.json",doc);    
	socket.Init(doc["Login"]);
	LoginMessage loginMessage;
	loginMessage.Init(socket);
	while(true){
		SendMessage(socket);
		socket.Loop();
		usleep(20);
	}
	
//	LoginServer server("LoginServer");
//	if(!server.LoadRes("Login.json")){
//		assert(false);
//	}
//
//






	return 0;
}
