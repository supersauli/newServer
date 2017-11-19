#ifndef __LUA_SYSTEM_H__
#define __LUA_SYSTEM_H__
extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

typedef lua_state luaSate;
typedef int (*luaFunc)(luaState*lua);

class LuaSystem
{

	public:
		bool Init();    
		bool LoadLuaFile(const char* luaFile_);
		void RegisterFunc(const char* funcName_,luaFunc func_);
	private:
		lua_State* _pLuaState;






};
#endif
