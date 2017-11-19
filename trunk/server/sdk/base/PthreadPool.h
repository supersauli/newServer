#ifndef _SPTHREADPOOL_H__
#define _SPTHREADPOOL_H__
#include "Pthread.h"
#include "Define.h"
#include <map>

class PthreadPool{

public:
	PthreadPool()
	{
		_poolIndex = 0;	
	}
	/**
	 * @brief 创建一个线程
	 */
	template <typename T>
	T*  CreateNewPthread(pthread_func func)
	{
		T *pth = new(std::nothrow) T(func);
		    return pth; 
	}

	/**
	 * @brief 添加线程到线程池
	 *
	 * @return 
	 */
	bool AddPthreadToPool(Pthread* pthread);

	/**
	 * @brief 根据索引找到线程
	 *
	 * @param dwIndex
	 *
	 * @return 
	 */
	Pthread* GetPhteadByIndex(DWORD dwIndex);

	DWORD GetPthreadSize(){return _poolIndex;};
private:
	std::map<DWORD ,Pthread*> _pthreadPool;
	typedef std::map<DWORD ,Pthread*>::iterator PTHREADIT;
	DWORD _poolIndex;
};
#endif
