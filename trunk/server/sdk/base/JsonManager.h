#ifndef __JSON_MANAGER__H__
#define __JSON_MANAGER__H__
#include "../third_part/json/document.h"
#include "../third_part/json/writer.h"
#include "../third_part/json/stringbuffer.h"
#include "../third_part/json/filereadstream.h"

#include "../base/HelpFunction.h"

namespace sdk
{
	#define Json rapidjson
	class JsonManager{
public:
	 static bool ParseFile(const char* fileName,Json::Document& doc);
	};
};






#endif
