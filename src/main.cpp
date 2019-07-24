#include <iostream>
#include <numeric>
#include <array>

#include "lua/zlua.hpp"
#include "lua/zlua.cpp"

#include "opengl/window.hpp"
#include "opengl/window.cpp"

#include <transform.hpp>
#include <object.hpp>
#include <mesh.hpp>

lua::lua_state Lua;

int main()
{
	zl::object myObject;

	Lua.openLibs();

	if (Lua.doFile("example.lua"))
	{
		// TODO
		
	}
	else
	{
		std::cerr << "[Lua] ERROR: " << Lua.toString(-1) << std::endl;
		return -1;
	}

	return 0;
}

/*

	lua_createtable(static_cast<lua_State*>(Lua.m_luaState), 0, 0);
	Lua.pushString("125string");
	lua_setfield(static_cast<lua_State*>(Lua.m_luaState), -2, "jez");
	lua_setglobal(static_cast<lua_State*>(Lua.m_luaState), "example");

*/