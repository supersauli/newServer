#ifndef __VAR_LIST_H__
#define __VAR_LIST_H__
//#include <list>
#include<vector>
#include <assert.h>

class VarObj
{
	public:	
		VarObj(int value):_value(value){
	}
	int GetValue(){
		return _value;
	}
	private:
		int _value;


};

class VarList
{

	public:

		int GetValue(int i)
		{
			assert(i<_varList.size());
			if(i>=_varList.size())	
			{
				return 0;
			}
			return _varList[i].GetValue();
		};

		VarList& operator<<(int value)
		{
			_varList.push_back(VarObj(value));	
			return *this;

		}
		inline int size(){
			return _varList.size();
		}


	private:	
		std::vector<VarObj> _varList;

};















#endif
