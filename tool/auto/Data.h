#ifndef __DATA_H__
#define __DATA_H__
#include<string>
#include<iostream>
#include<map>
#include<functional>
#include<set>
using namespace std::placeholders;
class ReflectData
{
    typedef std::function<int()>   GETINTCALLBACK;
    typedef std::function<const char*()>   GETSTRCALLBACK;
    typedef std::function<void(int)> SETINTCALLBACK;
    typedef std::function<void(const char*)> SETSTRCALLBACK;

    public:     

    int GetInt(const char* attrName){
        auto it = _getIntCB.find(attrName);
        if(it != _getIntCB.end()){
            return it->second();
        }
        return 0;
    };

    const char* GetStr(const char* attrName){
        auto it = _getStrCB.find(attrName);
        if(it != _getStrCB.end()){
            return it->second();
        }
        return "";
    }
    
    bool Set(const char* attrName ,int value){
        auto it  = _setIntCB.find(attrName);
        if(it != _setIntCB.end())
        {
            it->second(value);
            return true;
        }
        return false;
    }

    bool Set(const char* attrName ,const char* value){
        auto it  = _setStrCB.find(attrName);
        if(it != _setStrCB.end())
        {
            it->second(value);
            return true;
        }
        return false;
    }



    bool AddGetCallBack(const char* attrName,GETINTCALLBACK func){
        auto it  = _attrList.find(attrName);
        if(it != _attrList.end()){
            return false;
        }
        if(!_getIntCB.insert(std::make_pair(attrName,func)).second){
            return false; 
        };
        _attrList.insert(attrName);
        return true;
    };
    bool AddGetCallBack(const char* attrName,GETSTRCALLBACK func){
        auto it  = _attrList.find(attrName);
        if(it != _attrList.end()){
            return false;
        }

        if (!_getStrCB.insert(std::make_pair(attrName,func)).second){
            return false;
        }
        _attrList.insert(attrName);
        return true;
    };
    bool AddSetCallBack(const char* attrName,SETINTCALLBACK func){
        return _setIntCB.insert(std::make_pair(attrName,func)).second;
    };
    bool AddSetCallBack(const char* attrName,SETSTRCALLBACK func){
        return _setStrCB.insert(std::make_pair(attrName,func)).second;
    };

    std::set<std::string> GetAttrList(){
        return _attrList;
    };

    private:
        std::map<std::string,GETINTCALLBACK> _getIntCB;
        std::map<std::string,GETSTRCALLBACK> _getStrCB;
        std::map<std::string,SETINTCALLBACK> _setIntCB;
        std::map<std::string,SETSTRCALLBACK> _setStrCB;
        std::set<std::string> _attrList;

};


class Data
{
    public: 
        Data(){};
        int Save(char* buf);
        void Load(const char* buf);

        const char* GetName(){
            return name.c_str();
        };
        int GetLevel(){return level;};
        int GetAge(){return age;};

        void SetLevel(int value){level= value; }
        void SetAge(int value){age=value;}; 
        void SetName(const char* value){name=value;};
        
        int GetInt(const char*attrName){
            return _reflectdata.GetInt( attrName);
        };
        const char* GetStr(const char*attrName){
            return _reflectdata.GetStr( attrName);
        };


        void InitAttrCallBack(){

            _reflectdata.AddGetCallBack("name",std::bind(&Data::GetName,this));
            _reflectdata.AddGetCallBack("age",std::bind(&Data::GetAge,this));
            _reflectdata.AddGetCallBack("level",std::bind(&Data::GetLevel,this));
            _reflectdata.AddSetCallBack("name",std::bind(&Data::SetName,this,_1));
            _reflectdata.AddSetCallBack("age",std::bind(&Data::SetAge,this,_1));
            _reflectdata.AddSetCallBack("level",std::bind(&Data::SetLevel,this,_1));
        };
    
        template<typename T>
         bool  SetAttr(const char*attrName,T value){
             return _reflectdata.Set(attrName, value);
         };



        std::set<std::string> GetAttrList(){
            return _reflectdata.GetAttrList();
        };


    private:
        ReflectData _reflectdata;
        std::string name;
        int level;
        int age;
};



#endif
