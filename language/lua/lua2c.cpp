#include<iostream>
using namespace std;
#include<stdio.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
lua_State* L;
typedef lua_State LState;

static int average(LState* l)
{
	int n = lua_gettop(l);
	double sum = 0;
	for(auto i  =1;i<=n;i++)
	{
		if(!lua_isnumber(l,i))	
		{
			lua_pushstring(l,"Incorrect argument to 'average'");
			lua_error(l);
		
		}
		sum += lua_tonumber(l,i);
	}

	lua_pushnumber(l,sum/n);
	lua_pushnumber(l,sum);
	return 2;
}

int main()
{
	L = lua_open();
	luaL_openlibs(L);
	lua_register(L,"average",average);
	luaL_dofile(L,"test.lua");
	lua_getglobal(L,"avg");
	cout<<"avg is:"<<lua_tointeger(L,-1)<<endl;
	lua_pop(L,1);
	lua_getglobal(L,"sum");
	cout<<"sum is:"<<lua_tointeger(L,-1)<<endl;
	lua_close(L);

}

