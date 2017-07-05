#if 0
#include "head.h"
#include <stdio.h>
#include <iostream>
#include <iostream>
#include <string.h>
#include "sSctpPool.h"
#include "sPthreadPool.h"
#include "sdk/sMemPool.h"
#include "sLogManager.h"
#include "sdk/sTask.h"
#include "sTime.h"
#include "sdk/VarList.h"
#define LOG4_DEBUG(a,b) (a)->info((b));

using namespace std;
using namespace base;
//#if 1

void f1()
{
	cout<<"f1()"<<endl;
}
void f2(int a,int b)
{
	cout<<"f2()"<<a<<b<<endl;

}
#include "XmlFile.h"

int main()
{



	VarList var;
	var<<10;
	for(auto i = 0;i<var.size();i++)
	{
		cout<<var.GetValue(i)<<endl;
	
	}






//#if 0

	XmlFile xml;
	
	if(!xml.InitXml("DynamicActivity.xml"))
	{
		return false;	
	}

	auto root = xml.GetRootElement("story");

	if(root == nullptr){
		return false;
	}

	auto child = xml.GetChildNode(root,"storyinfo");
	if(child == nullptr){
		return false;
	}
	auto child1 = xml.GetChildNode(child,"author");

	std::string name;

	xml.GetNodeElement(child1,"author",name);


	cout<<name.c_str()<<endl;















	//Closure f1 = std::bind(&f1);
	//Closure f2 = std::bind(&f2,12,13);

//	Closure m1= std::bind(&f1);
//	Closure m2 = std::bind(&f2,2,0);
//	Closure m3 = std::bind(&f2,3,0);
//	Closure m4 = std::bind(&f2,4,0);
//	Closure m5 = std::bind(&f2,5,0);
//	Task task;
//
////	task.addTask(m1);
////	task.addTask(m2);
////	task.run();
////
//
//	task.addDelayTask(m1,1);
//	task.addDelayTask(m2,2);
//	task.addDelayTask(m3,3);
//	task.addDelayTask(m4,4);
//	task.addDelayTask(m5,5);
//	task.run();
//







	//base::logger.init("log4cplusconfig/urconfig.properties");	
//	base::logger.init(nullptr);	
	//base::logger.setLevel(LogLevel::LOG_LEVEL_ALL);	
	//while(1)
	{
//		for(int i = 0;i<10;i++)
		//base::logger.debug("This is value呵呵 %d",10);	
	}

		





//	sSctpPool sock;
//	if(!sock.initSocket())
//	{
//		 printf("false\n");
//		  return 0;
//	
//	};
//	if(!sock.bind(2222))
//	{
//		printf("false\n");	
//		return 0;
//	}
//
//
//	sock.initPool(1);
//	
//	sock.stcpAccept();


//	sPthreadPool spoll;
//	spoll.createNewPthread();
//
//
//		AA aa;
//		A* p = aa.getNewA();
//		printf("%lld\n",p);
//		delete p;





























//	sleep(10);
//	time_t timer;
//	time_t timer1;
//	struct timeval timer ,timer1;
//	gettimeofday(&timer,NULL);
//	//time(&timer);
//	sMutex mutex;
//	//time(&timer1);
//
//	gettimeofday(&timer1,NULL);
//	time_t s_time = (timer1.tv_sec - timer.tv_sec);
//	time_t result =( s_time *100000) + (timer1.tv_usec - timer.tv_usec);
//	printf("pass s time %lu \n",s_time);
//	printf("pass time %lu \n",result);
	return 0;
}
#endif

//
//bool addLocalFileLog(const std::string & file)
//{
//	log4cxx::PatternLayoutPtr fpl = new log4cxx::PatternLayout("\%d{\%y\%m\%d-\%H:\%M:\%S }%c %5p: %m%n");
//
//	log4cxx::DailyRollingFileAppender * farp = new log4cxx::DailyRollingFileAppender(fpl,file,"'.'yyMMdd-HH");
//	farp->setName("localfile:"+file);
//
//	log4cxx::Logger::getRootLogger()->addAppender(farp);
//
//	return true;
//}
#if 0
using namespace log4cxx;
using namespace log4cxx::helpers;

LoggerPtr logger(Logger::getLogger("MyApp"));

int main()
{

	Time time;
	//cout<<time.getCurTime()<<endl;
	time_t cur;
	cur= time.getCurTime();	
	time.printfTime(cur);
	struct tm curTm;

	time.getUtcTime(curTm);
	time.printfTime(curTm);

	time.getLocalTime(curTm);
	time.printfTime(curTm);


	log4cxx::PropertyConfigurator::configureAndWatch("log4cxx.properties");  
	log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("/home/sauli/log/output.log");  
	//LOG4_DEBUG(logger,"error");	
		for(int i = 0;i<1000000;i++)
		{
			char buf[1024];
			bzero(buf,sizeof(buf));
			sprintf(buf,"%d",i);
			logger->info(buf);
		}

	time_t cur1 = time.getCurTime();	
	time.printfTime(cur);
	time.printfTime(cur1);

	struct tm curTm1;
	time.getUtcTime(curTm);
	time.printfTime(curTm);

	time.getUtcTime(curTm1);
	time.printfTime(curTm1);

	//;time.getLocalTime(curTm);
	//time.printfTime(curTm);


	//log4cxx::LoggerPtr error = (log4cxx::Logger::getLogger("server.error"));

	//error->debug("This is a test");

	
//	BasicConfigurator::configure();
//	LOG4CXX_INFO(logger,"Entering application");










}
#endif
