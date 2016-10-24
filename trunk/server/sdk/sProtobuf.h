#ifndef __PROTOBUF_MANAGE_H__
#define __PROTOBUF_MANAGE_H__

//#include <boost/function.hpp>
//#include <boost/noncopyable.hpp>
//#include <boost/shared_ptr.hpp>

#include <google/protobuf/message.h>
#include <functional>
#include <string>
#include "sDefine.h"
#include <cstdlib>
typedef google::protobuf::Message			ProtoBuffMessage;
typedef google::protobuf::Descriptor		ProtoBuffDesc;
typedef google::protobuf::DescriptorPool    ProtoBuffDescPool;
typedef google::protobuf::MessageFactory    ProtoBuffMessageFactory;

class ProtobufManage//: std::noncopyable
{
	public:

		inline void recvMessage(void *buf){};

		inline void sendBuf(void *buf){};
	//private:
		
		/**
		 * @brief 创建消息
		 *
		 * @param name
		 *
		 * @return 
		 */
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


		/**
		 * @brief 编码
		 *
		 * @param buf
		 * @param message
		 */
		inline void decode(const char*buf,ProtoBuffMessage& message){
			std::string buffer; 
			const std::string& typeName = message.GetTypeName();
			DWORD nameLen = static_cast<DWORD>(typeName.size()+1);
			buffer.append(std::to_string(nameLen));
			buffer.append(typeName.c_str(),nameLen);
			DWORD byteSize = message.ByteSize();
			buffer.append(std::to_string(byteSize));
			buffer.append(message.SerializeAsString());

		};
		
		/**
		 * @brief 解码
		 *
		 * @param buf
		 */
		inline  ProtoBuffMessage* ecode(const char* buf)
		{

			std::string buffer(buf);
			int size = 0;
			int NameLen = std::atoi(buffer.substr(size,sizeof(DWORD)).c_str());	
			size+=sizeof(DWORD);
			std::string typeName = buffer.substr(size,NameLen);
			size+=NameLen;
			int contentSize = std::atoi(buffer.substr(size,sizeof(DWORD)).c_str());
			size+=sizeof(DWORD);
			ProtoBuffMessage* message;
			//google::protobuf::Message message;
			message = createMessage(typeName);
			if(message)
			{
				if(message->ParseFromArray(buffer.c_str()+size,contentSize))
				{
					return message;
				
				}
			}

			return nullptr;
		}


		

			


};




















#endif
