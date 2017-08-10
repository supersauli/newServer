#ifndef __TOOL_H__
#define __TOOL_H__
#include<string.h>
namespace sdk
{

	template<typename T>
		void PushData(char*&ptr,T& data)
		{
			bcopy(reinterpret_cast<T*>(&data),ptr,sizeof(T));   
			ptr+=sizeof(T);
		};
	template<>
		void PushData(char*&ptr, std::string&value)
		{
			unsigned int len = value.size();
			PushData(ptr,len);
			bcopy(value.c_str(),ptr,len);   
			ptr+=len;
		};


	template<typename T>
		void GetData(char*&ptr,T&data)
		{
			data = *(reinterpret_cast<T*>(ptr));
			ptr+=sizeof(T);
		}

	template<>
		void GetData(char*&ptr,std::string&value)
		{
			char buf[1024] = {}; 
			unsigned int len = 0;

			GetData(ptr,len);
			bcopy(ptr,buf,len);
			value.append(buf);
			ptr+=len;

		}

}





#endif
