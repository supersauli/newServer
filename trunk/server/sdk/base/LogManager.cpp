#include "LogManager.h"
#include "HelpFunction.h"
using namespace sdk;
void LogManager::Init(const char* configureFile,const char* nodeName)
{
	if(HF::CharIsNull(configureFile))
	{
		log4cplus::initialize();
		log4cplus::helpers::SharedObjectPtr<log4cplus::Appender> pShareAppend;
	    pShareAppend = new log4cplus::DailyRollingFileAppender("log/Test.log",log4cplus::DailyRollingFileSchedule::HOURLY,true);
		std::string pattern = "[%D{%Y-%m-%d %H:%M:%S}]%p%m%n";
		pShareAppend->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(pattern)));
		_logger = log4cplus::Logger::getRoot();
		_logger.setLogLevel(log4cplus::ALL_LOG_LEVEL);
		_logger.addAppender(pShareAppend);
	}
	else
	{
		log4cplus::initialize();
		log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(configureFile));
		if(HF::CharIsNull(nodeName))
		{
			_logger = log4cplus::Logger::getRoot(); 
		}
		else
		{
			_logger = log4cplus::Logger::getInstance(nodeName); 
		}
	}

}

void LogManager::SetLevel(const LogLevel& level)
{
	_logger.setLogLevel(static_cast<log4cplus::LogLevel>(level));
};

void LogManager::Debug(const char *fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};

	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_DEBUG_STR(_logger,buffer);

}





void LogManager::Trace(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};

	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_TRACE_STR(_logger,buffer);

}

void LogManager::Info(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};
	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_INFO_STR(_logger,buffer);
}

void LogManager::Warn(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};
	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_WARN_STR(_logger,buffer);

}


void LogManager::Error(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};
	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_ERROR_STR(_logger,buffer);
}

void LogManager::Fatal(const char*fmt,...)
{
	char buffer[LOG_BUFF_SIZE]= {0};
	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);
	LOG4CPLUS_FATAL_STR(_logger,buffer);
}

