#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__
//#include <log4cxx/logger.h>
//#include <log4cxx/basicconfigurator.h>
//#include <log4cxx/helper/exception.h>
//
//
//

/**
 * @brief 日志系统
 */

#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/layout.h>
#include <log4cplus/configurator.h>
#include <iostream>
#include <memory>
#define LOG_BUFF_SIZE 1024
//using namespace log4cplus;
//using namespace log4cplus::helpers;

namespace base{
	
	enum class LogLevel{
		LOG_LEVEL_ALL	= log4cplus::ALL_LOG_LEVEL,	
		LOG_LEVE_TRACE	= log4cplus::TRACE_LOG_LEVEL,
		LOG_LEVE_DEBUAG = log4cplus::DEBUG_LOG_LEVEL, 
		LOG_LEVE_INFO   = log4cplus::INFO_LOG_LEVEL,
		LOG_LEVE_WARN   = log4cplus::WARN_LOG_LEVEL,
		LOG_LEVE_ERROR	= log4cplus::ERROR_LOG_LEVEL,
		LOG_LEVE_FATAL  = log4cplus::FATAL_LOG_LEVEL,
		LOG_LEVE_OFF	= log4cplus::OFF_LOG_LEVEL,
	};




	class Logger{
		public:


			

			Logger()
			{
				std::string pattern = "%d{%m/%d/%y  %H:%M:%S}  - %m [%l]%n";
					
				_pLayout = new log4cplus::PatternLayout(pattern);	
			};
			~Logger(){
				log4cplus::Logger::shutdown();
			}
			/**
			 * @brief 初始化
			 */
			void init(const char* configureFile);

			/**
			 * @brief 设置等级
			 *
			 * @param dwLevel
			 */
			void setLevel(const LogLevel& level);


			/**
			 * @brief 调试
			 *
			 * @param fmt
			 * @param ...
			 */
			void debug(const char*fmt,...);

			void trace(const char*fmt,...);

			void info(const char*fmt,...);

			void warn(const char*fmt,...);

			void error(const char*fmt,...);

			void fatal(const char*fmt,...);





				
	//		static Logger& getInstance(){
	//			static Logger log;
	//			return log;
	//		}

		private:
			//log4cplus::SharedAppenderPtr _pShareAppend;
			log4cplus::helpers::SharedObjectPtr<log4cplus::Appender>  _pShareAppend;
			log4cplus::Layout *_pLayout;
			log4cplus::Logger _logger;
			//log4cplus::Logger _logger1;


	};

	static Logger logger;


};




#endif
