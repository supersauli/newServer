#include <stdio.h>
#include <iostream>
#include <iostream>
#include <string.h>
#include "Gate.h"
using namespace std;
using namespace sdk;
int main()
{

	SctpSocket socket;
	socket.SetIpAddress("127.0.0.1");
	socket.SetPort(4096);
	if(!socket.Connect()){
		printf("connect error \n");
	};
	socket.Init();

	socket.Write(socket.GetSocket(),"1111111");

	sleep(10);
	socket.Close(socket.GetSocket());

//	sSctpPool sock;
//	if(!sock.Init())
//	{   
//		printf("false\n");
//		return 0;
//
//	};  
//	if(!sock.Bind(2222))
//	{   
//		printf("false\n");  
//		return 0;
//	}   
//
//
//	sock.initPool(1);
//
	//sock.Loop();
}
