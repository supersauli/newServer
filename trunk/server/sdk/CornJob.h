#ifndef __CORN_JOB_H__
#define __CORN_JOB_H__
#include <list>
#include <functional>
#include "sTime.h"
/**
 * @brief 计划任务
 */


/**
 * @brief 计划函数
 */
typedef std::function<void()> CornFunc;


/**
 * @brief 计划描述
 */
struct CornDetails
{
	
	Time _executeTime;      //执行时间

	CornFunc _cornFunc; //执行内容

};

/**
 * @brief 排序
 */
struct CornSort
{
	bool operator ()(cosnt CornDetails&src,const CornDetails &obj)
	{
		if(src._time > obj._time)	
		{
			reutrn true;	
		}

		return false;
	}

};




class CornJob
{

	public:	
			
		static void AddACrontabTask(CornFunc,const char* strTime);	




	private:






};






#endif
