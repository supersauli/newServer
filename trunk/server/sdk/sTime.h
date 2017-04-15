#ifndef _STIME_H__
#define _STIME_H__
#include <time.h>
#include <stdio.h>
#include "sDefine.h"

class ClockTime{
	public:
		ClockTime(){
		clock_gettime(CLOCK_REALTIME,&_clockTime);		
	}

		/**
		 * @brief 刷新时间
		 */
	 void RefreshTimer()
	 {
		clock_gettime(CLOCK_REALTIME,&_clockTime);
	}

	/**
	 * @brief 获得秒数
	 *
	 * @return 
	 */
	 DWORD Sec()const
	 {
		return _clockTime.tv_sec;
	}

	/**
	 * @brief 获得毫秒数
	 *
	 * @return 
	 */
	 QWORD Msec()const
	{
		return _clockTime.tv_sec *1000LL + _clockTime.tv_nsec/1000000LL;
	}


	private:
	 	timespec		_clockTime;	


};
class Time final
{
	public:
		/**
		 * @brief 几几年
		 *
		 * @return 
		 */
		Time(){
			time(&_tTime) ;
			gmtime_r(&_tTime,&_tmTime);
		}

		/**
		 * @brief dwTime 是秒
		 *
		 * @param 
		 */
		Time(time_t dwTime):_tTime(dwTime){
			gmtime_r(&_tTime,&_tmTime);
		}

		/**
		 * @brief 刷新时间
		 */
		void Refresh(){
			time(&_tTime) ;
			gmtime_r(&_tTime,&_tmTime);
		}


		/**
		 * @brief 哪年
		 *
		 * @return 
		 */
		DWORD GetYear()const
		{
			return _tmTime.tm_year + 1900;		
		}

		/**
		 * @brief 哪个月 [1,12] 
		 *
		 * @return 
		 */
		DWORD GetMonth()const
		{
			return _tmTime.tm_mon +1 ;	
		}

		/**
		 * @brief 一个月中的日期[1,31]
		 *
		 * @return 
		 */
		DWORD GetMDay()const
		{
			return _tmTime.tm_mday ;	
		}

		/**
		 * @brief 周几(1-7)
		 *
		 * @return 
		 */
		DWORD GetWDay()const
		{
			if(_tmTime.tm_wday== 0){
				return 7;
			}
			return _tmTime.tm_wday;
		}

		/**
		 * @brief 从每年的1月1日开始的天数 [0,365]，其中0代表1月1日
		 *
		 * @return 
		 */
		DWORD GetYDay()const
		{
			return _tmTime.tm_yday;		
		
		}

		/**
		 * @brief 小时[0,23]　
		 *
		 * @return 
		 */
		DWORD GetHour()const
		{
			return _tmTime.tm_hour;
		}
		/**
		 * @brief 分钟数[0,59]
		 *
		 * @return 
		 */
		DWORD GetMinute()const
		{
			return _tmTime.tm_min;
		}

		/**
		 * @brief 秒数
		 *
		 * @return [0,59]
		 */
		DWORD GetSec()const
		{
			return _tmTime.tm_sec;
		}


		/**
		 * @brief 设置秒数
		 *
		 * @param time
		 */
		void setSec(const time_t&sec)
		{
			_tTime = sec;
			gmtime_r(&_tTime,&_tmTime);
		}

		/**
		 * @brief 增加延迟秒
		 *
		 * @param sec
		 */
		void addDelaySec(const time_t&sec)
		{
			_tTime += sec;	
			gmtime_r(&_tTime,&_tmTime);
		
		};

		/**
		 * @brief 获取延迟
		 *
		 * @param sec
		 *
		 * @return 
		 */
		int elapseSec(const time_t&sec)
		{
			return 	_tTime - sec ;

		}



		/**
		 * @brief 同一秒
		 *
		 * @param time
		 *
		 * @return 
		 */
		bool isSameSec(const time_t &time)const
		{

			if(GetSec() == Time(time).GetSec())
			{
				return true;
			}
			return false;
		}


		bool isSameSec(const Time &other)const
		{

			if(GetSec() == other.GetSec())
			{
				return true;
			}
			return false;
		}






		/**
		 * @brief 同一分钟
		 *
		 * @param time
		 *
		 * @return 
		 */
		bool isSameMinute(const time_t &time)const
		{
			if(GetMinute() == Time(time).GetMinute())	
			{
				return true;
			}
			return false;
		
		};


		bool isSameMinute(const Time &other)const
		{
			if(GetMinute() == other.GetMinute())	
			{
				return true;	
			}
		
			return false;	
		
		}





		bool operator > (const Time&other) const
		{
			return _tTime > other._tTime;
		
		}

		bool operator >= (const Time&other) const
		{
			return _tTime >= other._tTime;
		
		}



		bool operator < (const Time&other) const
		{
			return _tTime < other._tTime;
		
		}

		bool operator <= (const Time&other) const
		{
			return _tTime <= other._tTime;
		
		}


		bool operator == (const Time&other) const
		{
			return _tTime == other._tTime;
		
		}

		bool operator != (const Time&other) const
		{
			return _tTime != other._tTime;
		
		}

		Time& operator +(const Time&other)
		{
			_tTime +=  other._tTime;	
			gmtime_r(&_tTime,&_tmTime);
			return *this;

		}

		Time& operator - (const Time&other)
		{
		
			_tTime -=  other._tTime;	
			gmtime_r(&_tTime,&_tmTime);
			return *this;
		
		}

		Time& operator = (const Time&other)
		{

			_tTime = other._tTime;
			gmtime_r(&_tTime,&_tmTime);
			return *this;
		}



	private:
		struct tm _tmTime;
		//单位秒
		time_t _tTime;
};


static ClockTime _globaTime;








/**
 * @brief 循环时间
 */
class CycleTime
{

	public:

		CycleTime(const int& cycleMsec,const time_t&  msec = ClockTime().Msec()):_cycleMsec(cycleMsec)
		{
				_nextMsec = msec + _cycleMsec;
		}

		CycleTime(const int& cycleMsec,const Time& time):_cycleMsec(cycleMsec)
		{
			_nextMsec = time.GetSec()*1000 + cycleMsec;
		
		}


		/**
		 * @brief 重新计算时间
		 */
		void Reset(const time_t &time)
		{
			_nextMsec = time + _cycleMsec;
		
		};	

		/**
		 * @brief 设置毫秒周期
		 *
		 * @param msec 毫秒数
		 */
		void SetMsecCycle(int msec){
			_cycleMsec = msec;
		}


		/**
		 * @brief 秒设置秒周期
		 *
		 * @param sec
		 */
		void SetSec(int sec){
			_cycleMsec = sec*1000;
		}
		

		bool operator ()(const time_t& Msec)
		{
			if(_nextMsec>= Msec)	
			{
				Reset(Msec);
				return true;	
			}
			return false;
		}


	private:

		/**
		 * @brief 周期毫秒单位
		 */
		int _cycleMsec ;


		/**
		 * @brief 下一次时间(毫秒)
		 */
		time_t _nextMsec;

};












class TimeHelp
{
	public:
		/**
		 * @brief 是否是同一年
		 *
		 * @param src
		 * @param other
		 *
		 * @return 
		 */
	static bool isSameYear(time_t&src,time_t&other)
	{

		return Time(src).GetYear() == Time(other).GetYear();
	}
	

	/**
	 * @brief 是否是同一月
	 *
	 * @param src
	 * @param other
	 *
	 * @return 
	 */
	static bool isSameMonth(time_t&src,time_t&other)
	{
		return Time(src).GetMonth() == Time(other).GetMonth();
	}

	/**
	 * @brief 是否是同一天
	 *
	 * @param src
	 * @param other
	 *
	 * @return 
	 */
	static bool isSameDay(time_t&src,time_t&other)
	{
	
		Time sTime(src);
		Time oTime(other);
		if(sTime.GetYDay() == oTime.GetYDay() )
		{
			if(sTime.GetYear() == oTime.GetYear())	
			{
				return true;
			}
		
		}


		return false;
	}


	/**
	 * @brief 是否是同一周
	 *
	 * @param src
	 * @param other
	 *
	 * @return 
	 */
	static bool isSameWeek(time_t&src,time_t& other)
	{
		Time sTime(src);
		Time oTime(other);	
		if(sTime.GetYDay() - sTime.GetWDay() == oTime.GetYDay() - sTime.GetWDay())
		{
			if(sTime.GetYear() == oTime.GetYear())	
			{
				return true;	
			
			}
		
		}
		
		return false;
	
	}


	/**
	 * @brief 是否是同一小时(不关心是否为同一天)
	 *
	 * @param src
	 * @param other
	 *
	 * @return 
	 */
	static bool isSameHour(time_t&src,time_t&other) 
	{
		return 	Time(src).GetHour() == Time(other).GetHour();
	}


	/**
	 * @brief 是否是同一分钟(不关心是否为同一天同一小时)
	 *
	 * @param src
	 * @param other
	 *
	 * @return 
	 */
	static	bool isSameMinute(time_t&src,time_t&other)
	{
		if(Time(src).GetMinute() == Time(other).GetMinute())	
		{
			return true;	
		}

		return false;	
	}




};
typedef std::function<void()> TimerTasKFunc

clss TimerTask
{
	public:
		void AddCycle(int cycleTime,TimerTasKFunc&func);
	private:
//		std::list


};










#endif





