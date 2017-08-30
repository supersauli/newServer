#include "JsonManager.h"
using namespace sdk;
bool JsonManager::ParseFile(const char* fileName,Json::Document& doc)
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
	doc.Parse(jsonBuf);
	return true;

};



