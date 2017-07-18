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
#include <map>

#include "../base/Define.h"
#include "../base/HelpFunction.h"
typedef google::protobuf::Message			ProtoBuffMessage;
typedef google::protobuf::Descriptor		ProtoBuffDesc;
typedef google::protobuf::DescriptorPool    ProtoBuffDescPool;
typedef google::protobuf::MessageFactory    ProtoBuffMessageFactory;
namespace sdk
{
	class ProtobufManage//: std::noncopyable
	{
		private:
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

		public:
			/**
			 * @brief 编码
			 *
			 * @param buf
			 * @param message
			 */
			inline DWORD decode( char*buf,const ProtoBuffMessage& message)
			{
				int sendSize = 0;
				char *ptr =buf;
				const std::string& typeName = message.GetTypeName();
				DWORD nameLen = static_cast<DWORD>(typeName.size()+1);
				PushData(ptr,nameLen);
				sendSize += sizeof(DWORD);
				PushData(ptr,typeName.c_str(),nameLen);
				sendSize += nameLen;
				DWORD byteSize = message.ByteSize();
				sendSize += sizeof(DWORD);
				PushData(ptr,byteSize);
				PushData(ptr,message.SerializeAsString().c_str(),byteSize);	
				sendSize += byteSize;
				return sendSize;

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
				DWORD nameLen =0;
				memcpy(&nameLen,ptr,sizeof(int));	
				size += sizeof(DWORD);
				char typeName[100] = {0};
				memcpy(typeName,ptr+size,nameLen);
				size+=nameLen;
				int contentSize = 0;
				memcpy(&contentSize,ptr+size,sizeof(int));	
				size += sizeof(DWORD);
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


			inline void MessageDel(const char * buf){
				auto message= ecode(buf);	
				if(message == nullptr){
				    printf("ecode error\n");
					return ;	
				}

				const std::string& messageName =	message->GetTypeName();
				auto it = _messageDeal.find(messageName.c_str());
				if( it != _messageDeal.end())
				{
					it->second(message);	
				}
				else
				{
					printf("not found message %s \n",messageName.c_str());	
				}
				delete (message);
			};
	public:
			void AddMessageCallBack(const char* messageName,std::function<void(void*)> function ){
				if(HF::CharIsNull(messageName)){
					return ;
				}
				auto it =  _messageDeal.find(messageName);
				if(it != _messageDeal.end()){
					printf("message %s has regist \n ",messageName);
					return;
				}
				_messageDeal[messageName] = function;
			};

		private:
			std::map<std::string ,std::function<void(void*)>> _messageDeal;

	};

};
#endif
