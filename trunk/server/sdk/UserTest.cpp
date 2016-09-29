#include "UserTest.h"
#include "sPthread.h"
int dwSocket = 0;
UserTest* ss = NULL;
void * UserRun (void *)
{
    DWORD i = 0;
	while(true)
	{
		char buf[10];
		bzero(buf,sizeof(buf));
		sprintf(buf,"send %d",i);
	if(!(ss->sendCmd(dwSocket,buf)))
	{
		delete(ss);
		break;
	}
		i ++;	
//		if(sctp_sendmsg(dwSocket,buf,strlen(buf),0,0,0,0,0,0,0) <= 0)
//		{
//			
//			printf("%s\n",buf);
//		}
		usleep(1400);
	}

	return NULL;	

}

void UserTest::dealMsg(char *arg)
{
	printf("UserTest get Msg = %s \n",(char*)arg);
	dwSocket = _dwSocket;
	sPthread *pth = new sPthread(UserRun);
	ss = this;
	if(pth ==NULL)
	{
		printf("false");	
	}
}

bool UserTest::sendCmd(DWORD dwSocket,char *buf)
{
	if(end)
		return false;
	_sctpPth->sendCmd(dwSocket,buf);
	return true;

}


