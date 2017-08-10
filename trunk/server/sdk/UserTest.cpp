#include "UserTest.h"
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
	if(!(ss->SendCmd(dwSocket,buf)))
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
	Pthread *pth = new Pthread(UserRun);
	ss = this;
	if(pth ==NULL)
	{
		printf("false");	
	}
}

bool UserTest::SendCmd(DWORD dwSocket,char *buf)
{
	if(end)
		return false;
	_sctpPth->SendCmd(dwSocket,buf);
	return true;

}


