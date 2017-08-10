#include "Task.h"
bool Task::addTask(Closure&task)
{
	TaskContext taskContext(task);
	_taskList.push_back(taskContext);
	return true;

}


bool Task::addDelayTask(Closure&task,int delayTime)
{
	_delayTaskList.push_back(DelayTaskContext(task,delayTime));
	_delayTaskList.sort(DelayTaskCompare());
	return true;
}


void Task::run()
{
	for(auto i:_taskList)
	{
		(i._function)();
	
	}

	for(auto i:_delayTaskList)
	{
	
		(i._function)()	;
	
	}


}


