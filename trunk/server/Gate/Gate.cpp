#include <stdio.h>
#include <iostream>
#include <iostream>
#include <string.h>
#include "sSctpPool.h"
#include "sPthreadPool.h"



using namespace std;

int main()
{

	sSctpPool sock;
	if(!sock.initSocket())
	{   
		printf("false\n");
		return 0;

	};  
	if(!sock.bind(2222))
	{   
		printf("false\n");  
		return 0;
	}   


	sock.initPool(1);

	sock.stcpAccept();
}
