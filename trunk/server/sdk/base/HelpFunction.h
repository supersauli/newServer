#ifndef __HELP_FUNCTION_H__
#define __HELP_FUNCTION_H__

#include <random>
#include <time.h>
#include <set>

#include "sDefine.h"

namespace sdk{
	namespace HF{
	
		/**
		 * @brief 范围[numberic_limits<int>::min(),numberic_limits<int>::max()]
		 *
		 * @return 
		 */
	   inline int RandomInt(){
			return random();
		}

		/**
		 * @brief 范围[0,max]
		 *
		 * @param max
		 *
		 * @return 
		 */
		inline int RandomInt(const int& max){
			std::uniform_int_distribution<int>	 dis(0,max);
			return dis();
		}

		/**
		 * @brief 范围[min,max]
		 *
		 * @param min
		 * @param max
		 *
		 * @return 
		 */
		int RandomInt(const int& min,const int& max){
			std::uniform_int_distribution<int> dis(min,max);
			return dis();
		}

		/**
		 * @brief 范围[0.0, 1.0)
		 *
		 * @return 
		 */
		float RandomFloat(){
			std::uniform_real_distribution<float> dis;
			return dis();
		}

		/**
		 * @brief 范围[0.0,max)
		 *
		 * @param max
		 *
		 * @return 
		 */
		float RandomFloat(const float max){
			std::uniform_real_distribution<float> dis(0.0,max);
			return dis();
		}
	
		/**
		 * @brief 范围[min,max)
		 *
		 * @param min
		 * @param max
		 *
		 * @return 
		 */
		float RandomFloat(const float& min,const float& max){
			std::uniform_real_distribution<float> dis(min,max);
			return dis();
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
		bool DifferentInt(const DWORD& num,const int& min,const int& max,std::set<int>&diffNum ){
			int maxNum = std::max(min,max);
			int minNum = std::min(min,max);
			if(maxNum - minNum < num){
				return false;
			}
			std::uniform_int_distribution<int>	 dis(min,max);
			static int maxRandom = 100000000;
			int randomTimes = num;
			do{
			 int result = dis();
				auto it = diffNum.find(result);
				if(it == diffNum.end()){
					diffNum.insert(result);
					if(--randomTimes){
						break;
					}
				}


			}while(--maxRandom);

			

		}
	
	
	
	
	
	
	
	
	
	
	
	static std::default_random_engine random(time(NULL));	
	
	};















};





#endif
