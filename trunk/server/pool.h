#ifndef _POOL_H__
#define _POOL_H__
#include <stdio.h>
#include <string.h>
//链表长度
#define POOL_LIST_MAX_LENGTH 20
//最大内存管理
#define POOL_MANAGE_MAX_SIZE 128

union Memory{
	char data[1];
	union Memory* next;
};

struct Memory_List
{
	Memory *data;	
	Memory_List *next;

};


class sPool{

	public:
		bool init();
		void *getMalloc(int size);
		void freeMalloc(void *ptr,int size);	
		void deleteMalloc(void *ptr);
		bool allotMalloc(int index);
	private:
		Memory_List * _pool[POOL_LIST_MAX_LENGTH];




};





#endif
