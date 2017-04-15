#ifndef __TASK_H__
#define __TASK_H__
#include <functional>

typedef std::function<void()> TaskFunc;


class Task
{
	public:
		//跨场景怎么处理
		bool AddHeartTask(int cycle,TaskFunc &func);
	private:



};









#endif
