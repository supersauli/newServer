#ifndef __TOOL_H__
#define __TOOL_H__

#include<string.h>
#include <memory>
namespace sdk
{


	template<typename T>
		inline void PushData(char*&ptr,T& data)
		{
			bcopy(reinterpret_cast<T*>(&data),ptr,sizeof(T));   
			ptr+=sizeof(T);
		};

	template<>
		inline void PushData(char*&ptr,const std::string& data)
		{
			unsigned int len = data.size();
			PushData(ptr,len);
			bcopy(data.c_str(),ptr,len);   
			ptr+=len;
		};


	template<typename T>
		inline void GetData(char*&ptr,T&data)
		{
			data = *(reinterpret_cast<T*>(ptr));
			ptr+=sizeof(T);
		}

	template<>
		inline void GetData(char*&ptr,std::string&value)
		{
			char buf[1024] = {}; 
			unsigned int len = 0;

			GetData(ptr,len);
			bcopy(ptr,buf,len);
			value.append(buf);
			ptr+=len;

		}
};





#endif
