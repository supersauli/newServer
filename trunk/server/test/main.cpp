#include "sdk/base/VarList.h"
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <string.h>
#define BUFF_SIZE_MAX 1024
#include "sdk/sdk.h"
//#define TEXT_JSON "./ServerCfg/ipcfg.json"
#define TEXT_JSON "/home/sauli/server/Cfg/ServerCfg/ipcfg.json"
#include "../proto/ProtobufList.h"

using namespace std;
using namespace sdk;
void TestJson()
{
	FILE *fp = fopen(TEXT_JSON,"rb");
	assert(fp != nullptr);
	char json[1024]={0};
	rapidjson::FileReadStream(fp,json,sizeof(json));

	//const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	
    rapidjson::Document d;
	//d.open("../Cfg/ServerCfg/ipcfg.json");
    d.Parse(json);

    // 2. Modify it by DOM.
    rapidjson::Value& s = d["Gate"];
	if(s.IsObject())
	{
		//cout<<s.GetObject()<<endl;
			auto &ip =s["ip"];
			if(ip.IsString())
			{
				cout<<ip.GetString()<<endl;
			}
			auto &port = s["port"];
			if(port.IsInt())
			{
				cout<<port.GetInt()<<endl;
			}

	}

    // 3. Stringify the DOM
//    rapidjson::StringBuffer buffer;
//    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
//    d.Accept(writer);
//
//    // Output {"project":"rapidjson","stars":11}
//    std::cout << buffer.GetString() << std::endl;	
}


void TimerTaskTextFunc()
{
	cout<<__FILE__<<endl;
	cout<<ClockTime().GetMsec()<<endl;
}

typedef std::function<void()> Func;

void TestTimerTask(){
	TimerTaskManage task;
	Func c = &TimerTaskTextFunc;
	//task.AddCycleTask(1000,c,true);
	task.AddCountCycleTask(1000,10,c,true);


	while(true)
	{
		task.Update(ClockTime().GetMsec());	
		usleep(1);
	}

};


void func1(int a,int b){
	cout<<__FUNCTION__<<endl;
	cout<<"a="<<a<<",b="<<b<<endl;
};

void func2(int a,int b){
	cout<<__FUNCTION__<<endl;
	cout<<"a="<<a<<"b="<<b<<endl;
};

void func3(int *a ){
	cout<<__FUNCTION__<<endl;
	cout<<*a<<endl;
}
void func4(int *a,int b){
	cout<<__FUNCTION__<<endl;
}

enum {
	EVENT_1,
	EVENT_2,
};


int main()
{

	EventCallBack<> eventManage;
	eventManage.AddEventCallBackFunc(EVENT_1,std::bind(&func1,222,11111));
	eventManage.AddEventCallBackFunc(EVENT_1,std::bind(&func2,10,122),1);

	//eventManage.SendEvent(EVENT_1,10,100);
	//eventManage.SendEvent(EVENT_1);
	int m = 10;
	int *a = &m;
	EventCallBack<int*> eventManage1;

	eventManage1.AddEventCallBackFunc(EVENT_1,std::bind(&func1,222,11111));
	eventManage1.AddEventCallBackFunc(EVENT_1,std::bind(&func3,std::placeholders::_1),1);
	eventManage1.AddEventCallBackFunc(EVENT_1,std::bind(&func4,std::placeholders::_1,100),1);

	std::function<void(int,int)> ff = std::bind(&func1,std::placeholders::_1,std::placeholders::_2);
	ff(1,2);

	
	eventManage1.SendEvent(EVENT_1,a);



//	AddEventCallBackFunc
//	TestTimerTask();
//	TestJson();
//	sCompress com;
//	char src[BUFF_SIZE_MAX]="1234jfdosajflsdjflsa;fljdkls;afjdkls;afjdslkjfa;fjwfoewfjeofj;laskdjlsajf;lajfdlsa;jfdlks;afjeiwoafjeowfjo;fjqpojfofjsldfjks;afjeoiwfja;kdl;afjeofjihgghijfowjrfowfjdjflksjfdlfjldsjflsfjeiowuroeurourio3u58894759375893485028302ir204802840357908u9e20eipjdjljfldjsafldsfjlsdfjlsdjfeiowur9328u42040238402rowfjfjlsfjldjfljsjfeiruowruoeruowureowruoeuiowruoewrfjlfjlsjfeiruoewpruoeruopquroqprupoqrueowpqurejfljlsfjl;afjeowruoeruowpqruoiwrueporquipqruieoqwrupqrupqiwruowruqirupqrupoqriupqrjfjaslfjlasjfl;sfj;afj;djsfa;j3248203482084284820848402840842380238402e3ru9348rfu8ufjdsfjsdfslafjdlsfjlsdfjlasj567890123456909634223345565656767675654543434343454545";
//
//	int srcSize = strlen(src);
//
//	printf("src = %s\n",src);
//	char dest[BUFF_SIZE_MAX];
//	int a1 = com.Compress(src,dest,BUFF_SIZE_MAX,BUFF_SIZE_MAX);
//
//	int length = strlen(dest);
//	string aaa( dest,a1);
//	int destSize = aaa.size();
//	float ratio =(float) destSize/srcSize;	
//	printf("srcSize = %d,destSize = %d,radio = %f\n",srcSize,destSize,ratio);
//
//	printf("dest = %s\n",dest);
//	char decode[BUFF_SIZE_MAX]={0};
//	com.Decompress(dest,decode,BUFF_SIZE_MAX,BUFF_SIZE_MAX);
//
//	printf("decode = %s \n",decode);
//	if(strcmp(src,decode) !=0)
//	{
//		printf("error \n");
//	}
//	string u = "123\n233";
//	printf("%s\n",u.data());
//

//	sdk::ProtobufManage msg;
//	
//	muduo::pack mproto;
//	mproto.set_dwid(10);
//	mproto.set_name("fsdafd");
//	char buff[1024] = {0};
//	msg.decode(buff,mproto);	
//	while (true)
//	{
//	auto m1 = msg.ecode(buff);
//	cout<<m1->GetTypeName()<<endl;
//
//	auto m2 = (muduo::pack*)m1;
//	cout<<m2->dwid()<<endl;
//	}

//	Server serve;
//	serve.Init();
//	serve.LoadConfig("");
//	serve.Loop();



	HF::Text();









	XmlFile xml;
	xml.InitXml("guild_building_levelup_config.xml");
	
	auto root = xml.GetRootElement();

	auto children = xml.GetChildNode(root,"Property");
	if(children !=nullptr)	
	{

		do{
	
			DWORD a = 0;
			std::vector<std::string> ret;
			xml.GetNodeAttrList(children,ret);
			
			for(auto it :ret)
			{
				cout<<it.c_str()<<endl;
			}


			xml.GetNodeValue(children,"ID",a);
			;//std::string name;
			;//xml.GetNodeValue(children,"NAME",name);
			cout<<a<<endl;
			;//cout<<name.c_str()<<endl;
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


