#if 0
#include <stdio.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;



int main(){

	bitset<10> bitTest;
	bitTest.set(1,1111);

	//for(auto i = 0;i<bitTest.size();i++)
	{
		cout<<bitTest.to_string()<<endl;
	
	}




	string str = bitTest.to_string();
	cout<<bitTest.size()-bitTest.count()<<endl;
	bitTest.reset();

	cout<<bitTest.to_string()<<endl;
	bitset<10> ff(str);
	ff.flip();	
	bitTest = ff;
	cout<<bitTest.to_string()<<endl;
	cout<<bitTest[112]<<endl;
	return 0;
};
#endif
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <iomanip>
#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <time.h>
#include <string.h>
#include <log4cplus/loggingmacros.h>
#include <unistd.h>
using namespace std;
using namespace log4cplus;
Logger pTestLogger;
void writelog(char* leval,char* info)
{
	struct tm *p;
	time_t lt=time(NULL);
	p=localtime(&lt);
	char* timetemp=ctime(&lt);
	*(timetemp+strlen(timetemp)-1)='\0';
	char temp[10000];
	sprintf(temp,"[%s] %s",timetemp,info);
	        //printf("temp==%s",temp);
			//printf("leval====%s ",leval);
			if(memcmp(leval,"TRACE",5)==0)
				//printf("%d===%d\n",memcmp("TRACE","TRAC1E",5),memcmp(leval,"TRACE",5));
				memcmp("TRACE","TRAC1E",5),memcmp(leval,"TRACE",5);
			LOG4CPLUS_TRACE(pTestLogger,temp);
			if(memcmp(leval,"DEBUG",5)==0)
				LOG4CPLUS_DEBUG(pTestLogger,temp);
			if(memcmp(leval,"INFO",4)==0)
				LOG4CPLUS_INFO(pTestLogger,temp);
			if(memcmp(leval,"WARN",4)==0)
				LOG4CPLUS_WARN(pTestLogger,temp);
			if(memcmp(leval,"ERROR",5)==0)
				LOG4CPLUS_ERROR(pTestLogger,temp);
			if(memcmp(leval,"FATAL",5)==0)
				LOG4CPLUS_FATAL(pTestLogger,temp);
}
int main()
{
	char* info="you have a iuns";
	char filename[50];
	struct tm *p;
	time_t lt=time(NULL);
	p=localtime(&lt);
	sprintf(filename,"%d-%d-%d.txt",(1900+p->tm_year), (1+p->tm_mon),p->tm_mday);
	FILE* stream=fopen(filename,"wb");
	SharedAppenderPtr pFileAppender(new FileAppender((filename)));
	pTestLogger = Logger::getInstance("LoggerName");
	pTestLogger.addAppender(pFileAppender);
	while (true)
	{
		writelog("TRACE",info);
		writelog("DEBUG",info);
		writelog("ERROR",info);
	}
	        return 0;
}
