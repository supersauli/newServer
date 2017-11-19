#include "LogicServer.h"
#include "Package.h"
#include "../sdk/sdk.h"


enum class AttrType
{
    ATTR_TYPE_FLOAT,
    ATTR_TYPE_INT,
    ATTR_TYPE_DOUBLE,
    ATTR_TYPE_STR,
    ATTR_TYPE_LONG_LONG, 
    ATTR_TYPE_MAP,
};

template<typename T>
AttrType GetType(T){
    return AttrType::ATTR_TYPE_STR;
}

template<>
AttrType GetType(int){
    return  AttrType::ATTR_TYPE_INT;
}

template<>
AttrType GetType(DWORD){
    return  AttrType::ATTR_TYPE_INT;
}


template<>
AttrType GetType(float){
    return  AttrType::ATTR_TYPE_FLOAT;
}

template<>
AttrType GetType(double){
    return  AttrType::ATTR_TYPE_DOUBLE;
}


template<>
AttrType GetType(const char*){
    return  AttrType::ATTR_TYPE_STR;
}
template<typename T,typename M>
AttrType GetType(std::map<T,M>){
   return AttrType::ATTR_TYPE_MAP; 
}

template<>
AttrType GetType(char*){
    return  AttrType::ATTR_TYPE_STR;
}
template<typename T>
struct Type{
    typedef T TypeD;
};




template<typename T>
void PushData(char*&ptr,const char* attrName,T& value){
    //DWORD attrNameLen = strlen(attrName);
   // sdk::PushData(ptr,attrNameLen);
    sdk::PushData(ptr,attrName);
    auto type = GetType(value);    
    sdk::PushData(ptr,type);
    std::string strValue = sdk::HF::AsString(value); 
    sdk::PushData(ptr,strValue);
}

template<typename T>
void PopData(char*&ptr,const char* attrName,T& value){
    std::string sattrName;
    sdk::GetData(ptr,sattrName);
    AttrType attrType;

    sdk::GetData(ptr,attrType);
    auto valueType = GetType(value);
    std::string strValue ;
    sdk::GetData(ptr,strValue);
    if(attrType == valueType)
    {
        value = sdk::HF::AutoTransform<T>(strValue);
    }


}




#define PUSH_DATA(ptr,data) \
	PushData(ptr,#data,data); 
	
#define POP_DATA(ptr,data) \
    PopData(ptr,#data,data);






#include <stdio.h>

class SData{
	public:

	void Save(){
		char buf[1026] = {0};
		memcpy(buf,"100",3);
		//sdk::PushData(buf,);
	}
    /**
     * * @brief 
     * */
	void Load(){
	
	
	
	}
private:
//	std::string _saveData;
//	int _id{0};
//	bool _s{0};
//	std::string _name;

};


using namespace std;




class AFF{};

int main(){


    char buf[1024] = {0};
     char*in =&buf[0];
     char *out = &buf[0];
    int a  = 10;

    PUSH_DATA(in,a);
    a = 0;
    POP_DATA(out,a);
    cout<<a<<endl;





//    auto af1 = new AFF();
//    AFF f;
//    std::map<std::string,std::string> zz;
//    cout<<typeid(af1).name()<<endl;
//    cout<<typeid(f).name()<<endl;
//    cout<<typeid(zz).name()<<endl;
//    cout<<typeid(int).name()<<endl;
//    cout<<typeid(double).name()<<endl;
//    cout<<typeid(float).name()<<endl;
//    cout<<typeid(unsigned int).name()<<endl;
//

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
