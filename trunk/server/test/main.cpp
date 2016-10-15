#include "sdk/VarList.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "sdk/XmlFile.h"
using namespace std;
int main()
{


	XmlFile xml;
	xml.InitXml("DynamicActivity.xml");
	
	auto root = xml.GetRootElement();

	auto children = xml.GetChildNode(root,"Property");
	if(children !=nullptr)	
	{

		do{
	
			DWORD a = 0;
			xml.GetNodeValue(children,"ID",a);
			std::string name;
			xml.GetNodeValue(children,"NAME",name);
			cout<<a<<endl;
			cout<<name.c_str()<<endl;
			children = xml.GetNext(children);	
			
		}while(children != nullptr);

	
	}
































//	char buf[1024]={0};
//	void*start = &buf;
//	void*index = &buf;
//	//memcpy(index,"10",sizeof(int));	
//	//sprintf((char*)index,"%d",10);
//	int a  = 10;
//	bcopy(&a,reinterpret_cast<char*>(index),sizeof(int));
//	index=(char*)index +sizeof(int);
//	int b = 11;
//	bcopy(&b,reinterpret_cast<char*>(index),sizeof(int));
//	index=(char*)index +sizeof(int);
//	const char* ff = "abcdef";
//
//	bcopy(ff,reinterpret_cast<char*>(index),strlen(ff)+1);
//	//sprintf((char*)index,"%d",11);
//
//	//memcpy(index,"20",sizeof(int));	
//	
//	cout<<*((int*)start)<<endl;
//	cout<<*((int*)((char*)start+4))<<endl;
//	std::string value = (char*)start+8;
//	cout<<value.c_str()<<endl;

//cout<<buf<<endl;













//	VarList var;
//	var<<10<<100<<"ffff"<<true<<190<<10.123f<<123.435;
//	for(auto i = 0;i<var.size();i++)
//	{
//
//		
//
//
//	}
//
//	cout<<var.GetIntValue(0)<<endl;
//	cout<<var.GetIntValue(1)<<endl;
//	cout<<var.GetStrValue(2).c_str()<<endl;
//	cout<<var.GetBoolValue(3)<<endl;
//	cout<<var.GetDWValue(4)<<endl;
//	cout<<var.GetQWValue(5)<<endl;
//	cout<<var.GetFloatValue(5)<<endl;
//	cout<<var.GetDoubleValue(6)<<endl;
//	cout<<var.GetFloatValue(6)<<endl;
//
	return 0;
}

