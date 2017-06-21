#ifndef __STRING_HELP__H__
#define __STRING_HELP__H__

namespace StringHelp{

	bool CharIsNull(const char* str){
		if(str == nullptr || str[0] == '\0'){
			return false;
		}
		return true;	
	}













};






#endif
