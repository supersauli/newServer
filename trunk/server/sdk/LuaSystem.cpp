#include "LuaSystem.h"
bool LuaSystem::Init()
{
	_pLuaState = lua_open();
	if(_pLuaState == nullptr){
		return false;
	}

	luaL_openlibs(_pLuaState);

}

bool LuaSystem::LoadLuaFile(const char* luaFile_)
{
	 luaL_dofile(_pLuaState,luaFile_);


}

void LuaSystem::RegisterFunc(const char* funcName_,luaFunc func_)
{

	if(func_ == nullptr){
		return;
	}
	lua_register(_pLuaState,funcName_,func_);

}
