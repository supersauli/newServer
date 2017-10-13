#ifndef __DATA_H__
#define __DATA_H__
#include<string>
#include<iostream>
#include<map>
#include<functional>
#include<set>
#include "Define.h"
#include "Template.h"
#include "ReflectData.h"
using namespace std::placeholders;

struct Friend{
    void Hash2Key();
    const std::string GetFirstKey()const {return name;}
    const int GetSecondKey()const{return age;}
    std::string  name;
    int age;
    int id{111};

};

struct User{

    void Hash1Key();
    const std::string GetFirstKey()const {return userName;}
    std::string userName;
};



struct Npc{
    void Hash3Key();
    const std::string GetFirstKey()const{return name;};
    const int GetSecondKey()const {return sex;};
    const int GetThreeKey()const{return level;};

    std::string name;
    int sex;
    int level;


};


class Data :public ReflectData
{
    public: 
        Data(){};
        int Save(char* buf);
        void Load(const char* buf);

        const char* GetName(){
            return name.c_str();
        }
        int GetLevel(){return level;};
        int GetAge(){return age;};

        void SetLevel(int value){level= value;}
        void SetAge(int value){age=value;}
        void SetName(const char* value){name=value;}


        void InitAttrCallBack(){
            AddAttr("name");
            AddAttr("age");
            AddAttr("level");
            AddGetAttrCB("name",std::bind(&Data::GetName,this));
            AddGetAttrCB("age",std::bind(&Data::GetAge,this));
            AddGetAttrCB("level",std::bind(&Data::GetLevel,this));
            AddSetAttrCB<const char*>("name",std::bind(&Data::SetName,this,_1));
            AddSetAttrCB<int>("age",std::bind(&Data::SetAge,this,_1));
            AddSetAttrCB<int>("level",std::bind(&Data::SetLevel,this,_1));
        };


    private:
        std::string name;
        int level;
        int age;
};



#endif
