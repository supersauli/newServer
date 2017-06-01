#ifndef __PROTOBUF_MANAGE_H__
#define __PROTOBUF_MANAGE_H__

//#include <boost/function.hpp>
//#include <boost/noncopyable.hpp>
//#include <boost/shared_ptr.hpp>

#include <google/protobuf/message.h>
#include <functional>
#include <string>
#include <cstdlib>
#include <string.h>

#include "../base/sDefine.h"

typedef google::protobuf::Message			ProtoBuffMessage;
typedef google::protobuf::Descriptor		ProtoBuffDesc;
typedef google::protobuf::DescriptorPool    ProtoBuffDescPool;
typedef google::protobuf::MessageFactory    ProtoBuffMessageFactory;

class ProtobufManage//: std::noncopyable
{
	public:

		inline void recvMessage(void *buf){};

		inline void sendBuf(void *buf){};

		inline ProtoBuffMessage*  createMessage(const std::string& name){
			const ProtoBuffDesc *desc = ProtoBuffDescPool::generated_pool()->FindMessageTypeByName(name); 
			if(desc != nullptr )
			{
				const ProtoBuffMessage * prototype = ProtoBuffMessageFactory::generated_factory()->GetPrototype(desc); 
				if(prototype != nullptr)
				{
					return prototype->New();			
				}
			}
			return nullptr;
		};

		template<class DATA>
		void PushData(char*&buf,const DATA &data)
		{
			bcopy(reinterpret_cast<const BYTE*>(&data),buf,sizeof(DATA));	
			buf+=sizeof(DATA);
		};

		template<class DATA>
		void PushData(char*&buf,const DATA &data,int size)
		{
			//bcopy(reinterpret_cast<const BYTE*>(&data),buf,size);	
			bcopy(data,buf,size);	
			buf+=size;
		};


		/**
		 * @brief 编码
		 *
		 * @param buf
		 * @param message
		 */
		inline void decode( char*buf,const ProtoBuffMessage& message)
		{
			char *ptr =buf;
			const std::string& typeName = message.GetTypeName();
			DWORD nameLen = static_cast<DWORD>(typeName.size()+1);
			PushData(ptr,nameLen);
			PushData(ptr,typeName.c_str(),nameLen);
			DWORD byteSize = message.ByteSize();
			PushData(ptr,byteSize);
			PushData(ptr,message.SerializeAsString().c_str(),byteSize);	
		};


		
		/**
		 * @brief 解码
		 *
		 * @param buf
		 */
		inline  ProtoBuffMessage* ecode(const char* buf)
		{
			const char*ptr = buf;
			int size = 0;
			DWORD NameLen = *(ptr+size);	
			size += sizeof(DWORD);
			char typeName[12] = {0};
			bcopy((ptr+size),typeName,NameLen);
			size+=NameLen;
			int contentSize = *(ptr+size);
			size+=sizeof(DWORD);
			ProtoBuffMessage* message;
			message = createMessage(typeName);
			if(message)
			{
				if(message->ParseFromArray(ptr+size,contentSize))
				{
					return message;

				}
			}

			return nullptr;
		}

};

#endif
