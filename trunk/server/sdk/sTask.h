#ifndef _STASK_H__
#define _STASK_H__
#include <list>
#include <string.h>
#include <iostream>
#include <functional>
#include "sDefine.h"

typedef std::function<void()> Closure;
struct TaskContext{

	TaskContext(Closure function):
		_function(function)
	{}
	TaskContext& operator =  (TaskContext& other)
	{
		_function = other._function;
		return *this;
	}
	
	std::string		_taskName;	
	DWORD			_dwID;	
	Closure			_function;
};

struct DelayTaskContext
{

	DelayTaskContext(Closure function,int delayTime):
		_function(function),_delayTime(delayTime)
	{}

	Closure _function;
	int _delayTime;

};
struct DelayTaskCompare
{
	bool operator()(const DelayTaskContext & task1,const DelayTaskContext & task2)const
	{
		return task1._delayTime < task2._delayTime;
	}
};

//template <class T>
class Task
{
	public:
		 bool addTask(Closure&task);

		 bool delTask(Closure&task);

		 bool addDelayTask(Closure&task,int delayTime);
		 /**
		  * @brief 循环任务
		  *
		  * @param task 
		  * @param lastTime 
		  *
		  * @return 
		  */
		 bool addCycleTaskTime(Closure&task,int cycle,int lastTime = -1);

		 bool addCycleTaskCount(Closure&task,int cycle,int lastTime = -1);

		 void run();
	private:	
		std::list<TaskContext> _taskList;
		std::list<DelayTaskContext> _delayTaskList;

};



#endif
