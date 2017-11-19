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
namespace sdk{
	
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




	class LogManager{
		public:
			LogManager(){
			};
			~LogManager(){
				log4cplus::Logger::shutdown();
			}
			/**
			 * @brief 初始化
			 */
			void Init(const char* configureFile=nullptr,const char* nodeName=nullptr);

			/**
			 * @brief 设置等级
			 *
			 * @param dwLevel
			 */
			void SetLevel(const LogLevel& level);


			/**
			 * @brief 调试
			 *
			 * @param fmt
			 * @param ...
			 */
			void Debug(const char*fmt,...);

			void Trace(const char*fmt,...);

			void Info(const char*fmt,...);

			void Warn(const char*fmt,...);

			void Error(const char*fmt,...);

			void Fatal(const char*fmt,...);

		private:
			log4cplus::Logger _logger;
	};
};




#endif
