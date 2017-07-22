#ifndef __HELP_FUNCTION_H__
#define __HELP_FUNCTION_H__

#include <random>
#include <time.h>
#include <set>

#include "Define.h"

namespace sdk{
	class  HF{
		public:
			/**
			 * @brief 范围[numberic_limits<int>::min(),numberic_limits<int>::max()]
			 *
			 * @return 
			 */
			static int RandomInt();

			/**
			 * @brief 范围[0,max]
			 *
			 * @param max
			 *
			 * @return 
			 */
		     static int RandomInt(const int& max);

			/**
			 * @brief 范围[min,max]
			 *
			 * @param min
			 * @param max
			 *
			 * @return 
			 */
			static int RandomInt(const int& min,const int& max);

			/**
			 * @brief 范围[0.0, 1.0)
			 *
			 * @return 
			 */
			static float RandomFloat();

			/**
			 * @brief 范围[0.0,max)
			 *
			 * @param max
			 *
			 * @return 
			 */
			static float RandomFloat(const float max);

			/**
			 * @brief 范围[min,max)
			 *
			 * @param min
			 * @param max
			 *
			 * @return 
			 */
			 static float RandomFloat(const float& min,const float& max);

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
			 static bool DifferentInt(const DWORD& num,const int& min,const int& max,std::set<int>&diffNum );

			/**
			 * @brief  字符串是否为空
			 *
			 * @param str
			 *
			 * @return 
			 */
			static	bool CharIsNull(const char* str);

			/**
			 * @brief 得到crc 
			 *
			 * @param buf
			 * @param nLength
			 *
			 * @return 
			 */
			static DWORD GetCRC(const BYTE * buf,int nLength);


	};
};

#endif
