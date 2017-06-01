#ifndef _MAPMANAGE_H__
#define _MAPMANAGE_H__
#include <map>
template<typename K, typename V>
class MapManage
{
	public:
		MapManage(K& key,V& value){ 
		_keyValue.insert(std::make_pair(key,value));

		}


	private:
	
		static std::map<K,V> _keyValue;


};




#endif
