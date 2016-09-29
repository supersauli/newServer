#include "sLogManager.h"
using namespace base;
void Logger::init(const char* configureFile)
{


	if(configureFile == nullptr || configureFile[0] == '\0')
	{
		log4cplus::initialize();
	
//	//_pShareAppend = new log4cplus::FileAppender("Test.log");
//	_pShareAppend = new log4cplus::DailyRollingFileAppender("log/Test.log");
//	_pShareAppend->setName("fileLog");
//	
//
//	 std::string pattern = "%d{%m/%d/%y  %H:%M:%S}  - %m %p [%l]%n";
//	                         
//	 _pLayout = new log4cplus::PatternLayout(pattern);   
//	//_pLayout  =  new log4cplus::SimpleLayout();
//	 std::auto_ptr<log4cplus::Layout> pLayout (_pLayout);
//	_pShareAppend->setLayout(pLayout);
//	_logger = log4cplus::Logger::getInstance("111"); 
//	_logger.setLogLevel(static_cast<log4cplus::LogLevel>(LogLevel::LOG_LEVEL_ALL));
//	_logger.addAppender(_pShareAppend);
//
//


		_pShareAppend = new log4cplus::DailyRollingFileAppender("log/Test.log", log4cplus::DailyRollingFileSchedule::HOURLY, true);
		std::string pattern = "[%D{%Y-%m-%d %H:%M:%S}]%p%m%n";
		_pLayout = new log4cplus::PatternLayout(pattern);
		std::auto_ptr<log4cplus::Layout> pLayout(_pLayout);
		_pShareAppend->setLayout(pLayout);
		_logger = log4cplus::Logger::getRoot();
		_logger.setLogLevel(log4cplus::ALL_LOG_LEVEL);
		_logger.addAppender(_pShareAppend);


	}
	else
	{

		log4cplus::initialize();
		log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(configureFile));
		//_logger = log4cplus::Logger::getInstance("LOG1"); 
		_logger = log4cplus::Logger::getRoot(); 
		//_logger1 = log4cplus::Logger::getInstance("LOG2"); 

	
	}

}

void Logger::setLevel(const LogLevel& level)
{

	_logger.setLogLevel(static_cast<log4cplus::LogLevel>(level));

};

void Logger::debug(const char *fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};

	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
//	LOG4CPLUS_DEBUG(_logger,buffer);
	LOG4CPLUS_DEBUG_STR(_logger,buffer);
	//LOG4CPLUS_DEBUG_STR(_logger1,buffer);

}





void Logger::trace(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};

	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_TRACE_STR(_logger,buffer);

}

void Logger::info(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};

	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_INFO_STR(_logger,buffer);
}

void Logger::warn(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};

	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_WARN_STR(_logger,buffer);

}


void Logger::error(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};

	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_ERROR_STR(_logger,buffer);

}

void Logger::fatal(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};

	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_FATAL_STR(_logger,buffer);
}

