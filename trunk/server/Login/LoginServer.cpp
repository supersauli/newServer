#include "LoginServer.h"
#include <assert.h>
int main()
{

	LoginServer server("LoginServer");
	if(!server.LoadRes("Login.json")){
		assert(false);
	}








	return 0;
}
