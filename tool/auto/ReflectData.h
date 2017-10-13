#ifndef __REFLECT_DATA_H__
#define __REFLECT_DATA_H__
#include<string>
#include<iostream>
#include<map>
#include<functional>
#include<set>
#include "Define.h"
#include "Template.h"
using namespace std::placeholders;
class ReflectData
{
	private:
    /**
     * @brief GetCB
     */
    typedef std::function<int()>               GETINTCALLBACK;
    typedef std::function<const char*()>       GETSTRCALLBACK;
    typedef std::function<double()>            GETDOUBLECALLBACK;
    typedef std::function<float()>             GETFLOATCALLBACK;
    typedef std::function<INT64()>             GETINT64CALLBACK;

    /**
     * @brief SetCB
     */
    typedef std::function<void(int)>           SETINTCALLBACK;
    typedef std::function<void(const char*)>   SETSTRCALLBACK;
    typedef std::function<void(double)>            SETDOUBLECALLBACK;
    typedef std::function<void(float)>             SETFLOATCALLBACK;
    typedef std::function<void(DWORD)>             SETDOWRDCALLBACK;
    typedef std::function<void(INT64)>             SETINT64CALLBACK;


    public:     

	/**
	 * @brief 增加获取属相回调
	 *
	 * @tparam T
	 * @param attrName
	 * @param callBackFunc
	 *
	 * @return 
	 */
	template<typename T>
		bool AddGetAttrCB(const char*attrName ,T callBackFunc){
			using Type  = typename ResultOfType<T>::type; 
			return AddGetCB<Type>(attrName,callBackFunc);
		}

	/**
	 * @brief 设置属性回调
	 *
	 * @tparam T
	 * @param attrName
	 * @param func
	 *
	 * @return 
	 */
	template<typename T>
		bool AddSetAttrCB(const char* attrName,std::function<void(T)> func){
			return   AddSetCB<T>(attrName,func);
		}

	/**
	 * @brief 属性列表
	 *
	 * @return 
	 */
	const std::set<std::string>& GetAttrList(){
		return _attrList;
	}

	/**
	 * @brief 增加属性
	 *
	 * @param attrName
	 *
	 * @return 
	 */
	bool AddAttr(const char * attrName){
		auto it  = _attrList.find(attrName);
		if(it != _attrList.end()){
			return false;
		}
		_attrList.insert(attrName);
		return true;
	}



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
    
    INT64 GetInt64(const char* attrName){
        auto it = _getInt64CB.find(attrName);
        if(it != _getInt64CB.end()){
            return it->second();
        }
        return 0;
    }

    float GeFloat(const char* attrName){
        auto it = _getFloatCB.find(attrName);
        if(it != _getFloatCB.end()){
            return it->second();
        }
        return 0.0f;
    }

    double GetDouble(const char* attrName){
        auto it = _getDoubleCB.find(attrName);
        if(it != _getDoubleCB.end()){
            return it->second();
        }
        return 0;
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

    bool Set(const char* attrName ,double value){
        auto it  = _setDoubleCB.find(attrName);
        if(it != _setDoubleCB.end()){
            it->second(value);
            return true;
        }
        return false;
    }


    bool Set(const char* attrName ,float value){
        auto it  = _setFloatCB.find(attrName);
        if(it != _setFloatCB.end()){
            it->second(value);
            return true;
        }
        return false;
    }


    bool Set(const char* attrName ,INT64 value){
        auto it  = _setInt64CB.find(attrName);
        if(it != _setInt64CB.end()){
            it->second(value);
            return true;
        }
        return false;
    }
    
private:    


    template<typename T>
    bool AddGetCB(...){
        static_assert(Empty<T>::value,"error !");
        return true;
    }

    template<typename T>
    typename std::enable_if<is_int<T>::value ,bool>::type  AddGetCB(const char* attrName,GETINTCALLBACK func){
        if(!_getIntCB.insert(std::make_pair(attrName,func)).second){
            printf("add get int call back error! repetition get int callback! attrName = %s \n",attrName);
            return false; 
        };
        return true;
    }

    template<typename T>
    typename std::enable_if<is_char<T>::value ,bool>::type  AddGetCB(const char* attrName,GETSTRCALLBACK func){
        if (!_getStrCB.insert(std::make_pair(attrName,func)).second){
            printf("add get str call back error! repetition get str callback! attrName = %s \n",attrName);
            return false;
        }
        return true;
    }

    template<typename T>
    typename std::enable_if<is_char<T>::value ,bool>::type AddGetCB(const char* attrName,GETINT64CALLBACK func){
        if (!_getInt64CB.insert(std::make_pair(attrName,func)).second){
            printf("add get int64 call back error! repetition get int64 callback! attrName = %s \n",attrName);
            return false;
        }
        return true;
    }

    template<typename T>
     typename std::enable_if<is_float<T>::value ,bool>::type AddGetCB(const char* attrName,GETFLOATCALLBACK func){
        if (!_getFloatCB.insert(std::make_pair(attrName,func)).second){
            printf("add get float call back error! repetition get float callback! attrName = %s \n",attrName);
            return false;
        }
        return true;
    }

    template<typename T>
    typename std::enable_if<is_double<T>::value ,bool>::type AddGetCB(const char* attrName,GETDOUBLECALLBACK func){
        if (!_getDoubleCB.insert(std::make_pair(attrName,func)).second){
            printf("add get str call back error! repetition get str callback! attrName = %s \n",attrName);
            return false;
        }
        return true;
    }
   

    template<typename T>
    bool AddSetCB(...){
        static_assert(Empty<T>::value,"error !");
        return true;
    }

    template<typename T>
    typename std::enable_if<is_int<T>::value,bool>::type AddSetCB(const char* attrName,SETINTCALLBACK func){
        if( !_setIntCB.insert(std::make_pair(attrName,func)).second){
            printf("add set int call back error! repetition set int callback! attrName = %s \n",attrName);
            return false;
        }
        return true;
    }


    template<typename T>
    typename std::enable_if<is_char<T>::value,bool>::type  AddSetCB(const char* attrName,SETSTRCALLBACK func){
        if(! _setStrCB.insert(std::make_pair(attrName,func)).second){
            printf("add set str call back error! repetition set str callback! attrName = %s \n",attrName);
           return false; 
        };
        return true;
    }


    template<typename T>
    typename std::enable_if<is_double<T>::value,bool>::type AddSetCB(const char* attrName,SETDOUBLECALLBACK func){
        if(! _setDoubleCB.insert(std::make_pair(attrName,func)).second){
            printf("add set double call back error! repetition set double callback! attrName = %s \n",attrName);
           return false; 
        };
        return true;
    }

    template<typename T>
    typename std::enable_if<is_float<T>::value,bool>::type  AddSetCB(const char* attrName,SETFLOATCALLBACK func){
        if(! _setFloatCB.insert(std::make_pair(attrName,func)).second){
            printf("add set float call back error! repetition set float callback! attrName = %s \n",attrName);
           return false; 
        };
        return true;
    }

    template<typename T>
    typename std::enable_if<is_int64<T>::value,bool>::type  AddSetCB(const char* attrName,SETINT64CALLBACK func){
        if(! _setInt64CB.insert(std::make_pair(attrName,func)).second){
            printf("add set int46 call back error! repetition set int64 callback! attrName = %s \n",attrName);
           return false; 
        };
        return true;
    }


    


    private:
        std::map<std::string,GETINTCALLBACK>         _getIntCB;
        std::map<std::string,GETSTRCALLBACK>         _getStrCB;
        std::map<std::string,GETDOUBLECALLBACK>      _getDoubleCB;
        std::map<std::string,GETFLOATCALLBACK>       _getFloatCB;
        std::map<std::string,GETINT64CALLBACK>         _getInt64CB;

        std::map<std::string,SETINTCALLBACK>         _setIntCB;
        std::map<std::string,SETSTRCALLBACK>         _setStrCB;
        std::map<std::string,SETDOUBLECALLBACK>      _setDoubleCB;
        std::map<std::string,SETFLOATCALLBACK>       _setFloatCB;
        std::map<std::string,SETINT64CALLBACK>         _setInt64CB;


        std::set<std::string> _attrList;

};




#endif
