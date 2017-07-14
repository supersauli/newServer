#include "HelpFunction.h"
using namespace sdk;
std::default_random_engine urandom(time(NULL));	
/**
 * @brief 范围[numberic_limits<int>::min(),numberic_limits<int>::max()]
 *
 * @return 
 */
int HF::RandomInt(){
	return urandom();
}

/**
 * @brief 范围[0,max]
 *
 * @param max
 *
 * @return 
 */
int HF::RandomInt(const int& max){
	std::uniform_int_distribution<int>	 dis(0,max);
	return dis(urandom);
}

/**
 * @brief 范围[min,max]
 *
 * @param min
 * @param max
 *
 * @return 
 */
int HF::RandomInt(const int& min,const int& max){
	std::uniform_int_distribution<int> dis(min,max);
	return dis(urandom);
}

/**
 * @brief 范围[0.0, 1.0)
 *
 * @return 
 */
float HF::RandomFloat(){
	std::uniform_real_distribution<float> dis;
	return dis(urandom);
}

/**
 * @brief 范围[0.0,max)
 *
 * @param max
 *
 * @return 
 */

float HF::RandomFloat(const float max){
	std::uniform_real_distribution<float> dis(0.0f,max);
	return dis(urandom);
}

/**
 * @brief 范围[min,max)
 *
 * @param min
 * @param max
 *
 * @return 
 */
float HF::RandomFloat(const float& min,const float& max){
	std::uniform_real_distribution<float> dis(min,max);
	return dis(urandom);
}

/**
 * @brief 获得一定范围内的不重复整数
 *
 * @param num 获得不重复整数数量
 * @param min
 * @param max
 * @param diffNum 结果
 *
 * @return 
 */
bool HF::DifferentInt(const DWORD& num,const int& min,const int& max,std::set<int>&diffNum ){
	int maxNum = std::max(min,max);
	int minNum = std::min(min,max);
	if(maxNum - minNum < num){
		return false;
	}
	std::uniform_int_distribution<int>       dis(min,max);
	static int maxRandom = 100000000;
	int randomTimes = num;
	do{
		int result = dis(urandom);
		auto it = diffNum.find(result);
		if(it == diffNum.end()){
			diffNum.insert(result);
			if(--randomTimes){
				break;
			}
		}
	}while(--maxRandom);
	return true;
}

/**
 * @brief  字符串是否为空
 *
 * @param str
 *
 * @return 
 */
bool HF::CharIsNull(const char* str){
	if(str == nullptr || str[0] == '\0'){
		return true;
	}
	return false;
}





