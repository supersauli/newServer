#include "Login.h"
#include "../sdk/sdk.h"
#include <assert.h>
#include "../proto/ProtobufList.h"
using namespace sdk;
ServerSocket *globalSocket;
int old = -1;
void Info(void*message)
{
	auto res  = static_cast<GateServer::UserLogin*>(message);
	//assert( res->dwid() - old == 1);
	old = res->dwid();

	std::cout<<res->dwid()<<std::endl;

	LoginProto::Result msg;
	msg.set_dwid( res->dwid());
	msg.set_result(true);
	globalSocket->SendMessage(msg);


}


int main()
{

	{GateServer::UserLogin s;}
	ServerSocket socket;
	globalSocket = &socket;
	Json::Document doc;
	JsonManager::OpenFile("/home/sauli/server/cfg/servercfg/ipcfg.json",doc);    
	socket.Init(doc["Login"]);
	socket.AddMessageCallBack("GateServer.UserLogin",Info);
	socket.Run();





//	LoginServer server("LoginServer");
//	if(!server.LoadRes("Login.json")){
//		assert(false);
//	}
//
//






	return 0;
}
