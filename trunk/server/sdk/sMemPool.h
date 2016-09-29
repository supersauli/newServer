#ifndef _SMEMPOOL_H__
#define _SMEMPOOL_H__
#include <stdio.h>

class sMem{
	public:
		static void * sAllocate(size_t size);
		static void	  sReallocate(void *p);
		static void * sReallocate(void *p,size_t size);
	private:
		
};








//内存池
class sMemPool{

	public:
		static void* sAllocate(size_t  size);
		static void  sDeallocate(void *p);
		static void* sReallocate(void *p,size_t size); 



	private:


};


#endif
