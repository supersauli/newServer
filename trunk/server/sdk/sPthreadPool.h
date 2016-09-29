#ifndef _SPTHREADPOOL_H__
#define _SPTHREADPOOL_H__
#include "sPthread.h"
#include "sDefine.h"
#include <map>

class sPthreadPool{

public:
	sPthreadPool()
	{
		_poolIndex = 0;	
	}
	/**
	 * @brief 创建一个线程
	 */
	template <typename T>
	T*  createNewPthread(pthread_func func)
	{
		T *pth = new T(func);
		    return pth; 
	}

	/**
	 * @brief 添加线程到线程池
	 *
	 * @return 
	 */
	bool addPthreadToPool(sPthread* pthread);

	/**
	 * @brief 根据索引找到线程
	 *
	 * @param dwIndex
	 *
	 * @return 
	 */
	sPthread* getPhteadByIndex(DWORD dwIndex);

	DWORD getPthreadSize(){return _poolIndex;};
private:
	std::map<DWORD ,sPthread*> _pthreadPool;
	typedef std::map<DWORD ,sPthread*>::iterator PTHREADIT;
	DWORD _poolIndex;
};
#endif
