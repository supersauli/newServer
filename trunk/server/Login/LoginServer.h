#ifndef __LOGIN_SERVER_H__
#define __LOGIN_SERVER_H__
#include <iostream>
#include <string>

class LoginServer
{
	public:
	
	LoginServer(const char* name):_serverName(name){}
	//bool LoadRes(const char* file);


	private:
		std::string _serverName;


};
#endif
