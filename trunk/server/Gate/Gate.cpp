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
	if(!sock.Init())
	{   
		printf("false\n");
		return 0;

	};  
	if(!sock.Bind(2222))
	{   
		printf("false\n");  
		return 0;
	}   


	sock.initPool(1);

	//sock.Loop();
}
