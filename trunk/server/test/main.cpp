#include "sdk/VarList.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "sdk/XmlFile.h"
#include "test.pb.h"
#include "sdk/sProtobuf.h"
#include "sdk/sServer.h"
using namespace std;
#include "sdk/sCompress.h"
#define BUFF_SIZE_MAX 1024
int main()
{
	sCompress com;
	char src[BUFF_SIZE_MAX]="1234jfdosajflsdjflsa;fljdkls;afjdkls;afjdslkjfa;fjwfoewfjeofj;laskdjlsajf;lajfdlsa;jfdlks;afjeiwoafjeowfjo;fjqpojfofjsldfjks;afjeoiwfja;kdl;afjeofjihgghijfowjrfowfjdjflksjfdlfjldsjflsfjeiowuroeurourio3u58894759375893485028302ir204802840357908u9e20eipjdjljfldjsafldsfjlsdfjlsdjfeiowur9328u42040238402rowfjfjlsfjldjfljsjfeiruowruoeruowureowruoeuiowruoewrfjlfjlsjfeiruoewpruoeruopquroqprupoqrueowpqurejfljlsfjl;afjeowruoeruowpqruoiwrueporquipqruieoqwrupqrupqiwruowruqirupqrupoqriupqrjfjaslfjlasjfl;sfj;afj;djsfa;j3248203482084284820848402840842380238402e3ru9348rfu8ufjdsfjsdfslafjdlsfjlsdfjlasj567890123456909634223345565656767675654543434343454545";

	int srcSize = strlen(src);

	printf("src = %s\n",src);
	char dest[BUFF_SIZE_MAX];
	int a1 = com.Compress(src,dest,BUFF_SIZE_MAX,BUFF_SIZE_MAX);

	int length = strlen(dest);
	string aaa( dest,a1);
	int destSize = aaa.size();
	float ratio =(float) destSize/srcSize;	
	printf("srcSize = %d,destSize = %d,radio = %f\n",srcSize,destSize,ratio);

	printf("dest = %s\n",dest);
	char decode[BUFF_SIZE_MAX]={0};
	com.Decompress(dest,decode,BUFF_SIZE_MAX,BUFF_SIZE_MAX);

	printf("decode = %s \n",decode);
	if(strcmp(src,decode) !=0)
	{
		printf("error \n");
	}
	string u = "123\n233";
	printf("%s\n",u.data());



//	ProtobufManage msg;
//	
//	muduo::pack mproto;
//	mproto.set_dwid(10);
//	mproto.set_name("fsdafd");
//	char buff[1024] = {0};
//	msg.decode(buff,mproto);	
//	auto m1 = msg.ecode(buff);
//	auto m2 = (muduo::pack*)m1;
//	cout<<m2->dwid()<<endl;
//
//	sServer serve;
//	serve.Init();
//	serve.LoadConfig("");
//	serve.Loop();













//	XmlFile xml;
//	xml.InitXml("DynamicActivity.xml");
//	
//	auto root = xml.GetRootElement();
//
//	auto children = xml.GetChildNode(root,"Property");
//	if(children !=nullptr)	
//	{
//
//		do{
//	
//			DWORD a = 0;
//			xml.GetNodeValue(children,"ID",a);
//			std::string name;
//			xml.GetNodeValue(children,"NAME",name);
//			cout<<a<<endl;
//			cout<<name.c_str()<<endl;
//			children = xml.GetNext(children);	
//			
//		}while(children != nullptr);
//
//	
//	}
//































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

