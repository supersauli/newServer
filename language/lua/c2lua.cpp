#include <stdio.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
lua_State* L;
int luadd(int x,int y)
{
	int sum;
	lua_getglobal(L,"add"); int nTop = lua_gettop(L);printf("nTop:%d",nTop);
	lua_pushnumber(L,x); nTop = lua_gettop(L);printf("nTop:%d",nTop);
	lua_pushnumber(L,y); nTop = lua_gettop(L);printf("nTop:%d",nTop);
	lua_call(L,2,1);    nTop = lua_gettop(L);printf("nTop:%d",nTop);
	sum = (int)lua_tonumber(L,-1); nTop = lua_gettop(L);printf("nTop:%d",nTop);
	lua_pop(L,1); nTop = lua_gettop(L);printf("nTop:%d",nTop);
	lua_pop(L,1); nTop = lua_gettop(L);printf("nTop:%d",nTop);
	lua_getglobal(L,"z"); nTop = lua_gettop(L);printf("nTop:%d",nTop);
	int z = (int)lua_tonumber(L,1); nTop = lua_gettop(L);printf("nTop:%d",nTop);
	lua_pop(L,1); nTop = lua_gettop(L);
	return sum;	

}
int main()
{
	int sum;
	L = lua_open();
	luaL_dofile(L,"c2lua.lua");
	sum = luadd(10,15);
	printf("The sum is %d",sum);
	lua_close(L);
	return 0;


}
