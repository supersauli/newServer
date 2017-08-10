#ifndef __JSON_MANAGER__H__
#define __JSON_MANAGER__H__
#include "sdk/third_part/json/document.h"
#include "sdk/third_part/json/writer.h"
#include "sdk/third_part/json/stringbuffer.h"
#include "sdk/third_part/json/filereadstream.h"

#include "sdk/base/HelpFunction.h"

namespace sdk
{
   #define Json rapidjson

	bool OpenFile(const char* fileName,Json::Document& doc)
	{
		if(HF::CharIsNull(fileName)){
			return false;
		}

		FILE *fp = fopen(fileName,"rb");
		if(fp == nullptr){
			return false;
		}
		char jsonBuf[10*1024]={0};
		Json::FileReadStream(fp,jsonBuf,sizeof(jsonBuf));
		doc.Clear();
		doc.Parse(jsonBuf);
		return true;

	};

	












};






#endif
