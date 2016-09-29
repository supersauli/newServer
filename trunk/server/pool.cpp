#include "pool.h"
#define  ALIGN 8
#define CHUNK_SIZE 1000 //每次分配多少个块
static  int GET_INDEX(int x)
{
	return ((x + ALIGN -1)/ALIGN -1);
}
 bool sPool::init()
{
	_pool[0] = new Memory_List; 	
	for(int i = 1;i<POOL_LIST_MAX_LENGTH;i++)
	{
		_pool[i] = new Memory_List;
		_pool[i]->data = NULL;
		_pool[i-1]->next = _pool[i];
	}
	return true;
}

void * sPool::getMalloc(int size)
{
	int index = GET_INDEX(size);
	if(index >= POOL_LIST_MAX_LENGTH)
		return NULL;
	Memory* memory = 	_pool[index]->data;
	if(memory == NULL)
	{
		if(allotMalloc(index))
			return NULL	;
		memory =    _pool[index]->data;
		if(memory == NULL)
			return NULL;
	}
	_pool[index]->data = memory->next;		
	return memory;
}

bool sPool::allotMalloc(int index)
{
	int size = ALIGN*(index+1)*CHUNK_SIZE; 
	char *ptr = new char[size];
	if(ptr == NULL)
		return false;
	bzero(ptr,size);
	_pool[index]->data = (Memory*)ptr;
	for(int i = 0;i<CHUNK_SIZE-1;i++)
	{
		Memory *mem = (Memory*)ptr;
		ptr = ptr + (index+1)*ALIGN;
	    mem->next = (Memory*)ptr;
	}
//	printf("重新分配内存\n");
}

void sPool::freeMalloc(void *ptr,int size)
{

	Memory*data = (Memory*)ptr;
	data->next = _pool[GET_INDEX(size)]->data;
	_pool[GET_INDEX(size)]->data = data;

};
