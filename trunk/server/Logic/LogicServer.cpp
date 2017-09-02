#include "LogicServer.h"
#include "Package.h"
#include "../sdk/sdk.h"

#define PUSH_DATA(ptr,data) \
	int attr##data##NameLen = strlen(#data); \
	sdk::PushData(ptr,attr##data##NameLen); \
	sdk::PushData(ptr,#data); \
	int attr##data##NameLen = strlen(data); \
	sdk::PushData(ptr,data);
	
#define POP_DATA(ptr,data) \
		std::map<std::string,std::string> attrMap;
		






#include <stdio.h>

class SData{
	public:


	void Save(){
		char buf[1026] = {0};
		memcpy(buf,"100",11);
		//sdk::PushData(buf,);
	
	
	};
	void Load(){
	
	
	
	
	}
private:
//	std::string _saveData;
//	int _id{0};
//	bool _s{0};
//	std::string _name;


};


using namespace std;






int main(){


//PUSH_DATA(buf,10);

//	PackageBase<Item,100>	 pack("test");
//	pack.Add("id",1);
//	pack.Add("id",1);
//	
//	PackageBase<Hero,100>	 pack1("test");
//
//	pack1.Add("id",1);
//	pack1.Add("id",1);
	return 0;
}
