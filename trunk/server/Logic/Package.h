#ifndef __PACKAGE_H__
#define __PACKAGE_H__
#include <map>
#include <iostream>
#include <memory>
#include <string>
template<typename ValueType>
struct  Property{
	Property(const char* name,ValueType value):_strName(name),_value(value){};
	Property(){};
	std::string _strName;
	ValueType _value{0};
};
#define PACKAGE_POS_MAX 100;
struct  ObjectBase{
	std::string _name;
	/**
	 * @brief 当前数量
	 */
	int _num{0};

	/**
	 * @brief 是否可叠加
	 */
	bool _isOverlay{false};

};

/**
 * @brief 属性组
 */
struct  PropertyGroup{
	PropertyGroup():_att("att",0),
					_hp("hp",0),
					_mp("mp",0),
					_def("def",0)
	{
		
	};


	Property<int> _att;
	Property<int> _hp;
	Property<int> _mp;
	Property<float> _def;
};

class Item:public ObjectBase
{
  public:
	PropertyGroup _propertyGroup;	
};

/**
 * @brief 管理对象
 */
typedef std::shared_ptr<ObjectBase> PackManageObj;
template<typename ObjFactory, int maxPos>
class PackageBase{

	public:
		PackageBase(const char* name):_packageName(name){}
		bool Add(const char* objID,int num);

	protected:

		int _maxPosSize;
		int _posSizeNow;
		std::string _packageName;
		std::map<std::string,PackManageObj> _objectMap;
		std::array<PackManageObj,maxPos> _objectArray;

};
template<typename T>
struct  ObjFactory{
	static PackManageObj CreateObj(const char*ID);

};


template<>
PackManageObj ObjFactory<Item>::CreateObj(const char*ID){
	std::cout<<"createItem"<<std::endl;
	 return std::make_shared<Item>();
 }
class Hero{};
template<>
PackManageObj ObjFactory<Hero>::CreateObj(const char*ID){
	std::cout<<"Hero"<<std::endl;
	
	 return std::make_shared<Item>();
 }




template<typename T,int maxPos>
bool PackageBase<T,maxPos>::Add(const char* objID,int num)
{
	auto it =   _objectMap.find(objID);
	if(it != _objectMap.end())
	{   
		it->second->_num +=num; 
	}   
	else
	{   
		_objectMap[objID] = ObjFactory<T>::CreateObj(objID);
	}
	return true;
};





#endif

