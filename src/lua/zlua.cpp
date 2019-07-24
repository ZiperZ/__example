#include "zlua.hpp"

#include <lua/lua.hpp>
#include <fstream>

inline lua::lua_state::lua_state()
{
	m_luaState = static_cast<luaState>(luaL_newstate());

	if (m_luaState == nullptr)
	{
		std::exception("Cannot create lua virtual machine. (No further info)");
	}
}

inline lua::lua_state::~lua_state()
{
	lua_close(static_cast<lua_State*>(m_luaState));
}

inline bool lua::lua_state::doFile(const std::string& fileName)
{
	return (bool) luaL_dofile(static_cast<lua_State*>(m_luaState), fileName.c_str()) == LUA_OK;
}

inline bool lua::lua_state::doString(const std::string& str)
{
	return (bool) luaL_dostring(static_cast<lua_State*>(m_luaState), str.c_str()) == LUA_OK;
}

inline void lua::lua_state::getGlobal(const std::string& name)
{
	lua_getglobal(static_cast<lua_State*>(m_luaState), name.c_str());
}

inline void lua::lua_state::setGlobal(const std::string& name)
{
	lua_setglobal(static_cast<lua_State*>(m_luaState), name.c_str());
}

inline void lua::lua_state::openLibs()
{
	luaL_openlibs(static_cast<lua_State*>(m_luaState));
}

inline void lua::lua_state::pushString(const std::string& str)
{
	lua_pushstring(static_cast<lua_State*>(m_luaState), str.c_str());
}

inline void lua::lua_state::pushInteger(int64_t val)
{
	lua_pushinteger(static_cast<lua_State*>(m_luaState), val);
}

inline void lua::lua_state::pushNumber(double val)
{
	lua_pushnumber(static_cast<lua_State*>(m_luaState), val);
}

inline void lua::lua_state::pushTable()
{
	lua_newtable(static_cast<lua_State*>(m_luaState));
}

void lua::lua_state::setField(int32_t index, const std::string& keyName)
{
	lua_setfield(static_cast<lua_State*>(m_luaState), index, keyName.c_str());
}

void lua::lua_state::addTableKey(int32_t index, const std::string& val, const std::string& key)
{
	pushString(val);
	setField(index, key);
}

void lua::lua_state::addTableKey(int32_t index, double val, const std::string& key)
{
	pushNumber(val);
	setField(index, key);
}

inline void lua::lua_state::pop(int32_t count)
{
	lua_pop(static_cast<lua_State*>(m_luaState), count);
}

inline bool lua::lua_state::isNumber(int32_t i)
{
	return lua_isnumber(static_cast<lua_State*>(m_luaState), i);
}

inline bool lua::lua_state::isInteger(int32_t i)
{
	return lua_isinteger(static_cast<lua_State*>(m_luaState), i);
}

inline bool lua::lua_state::isString(int32_t i)
{
	return lua_isstring(static_cast<lua_State*>(m_luaState), i);
}

inline bool lua::lua_state::isTable(int32_t i)
{
	return lua_istable(static_cast<lua_State*>(m_luaState), i);
}

inline bool lua::lua_state::isBoolean(int32_t i)
{
	return lua_isboolean(static_cast<lua_State*>(m_luaState), i);
}

inline bool lua::lua_state::isFunction(int32_t i)
{
	return lua_isfunction(static_cast<lua_State*>(m_luaState), i);
}

inline bool lua::lua_state::getTable(int32_t i)
{
	return lua_gettable(static_cast<lua_State*>(m_luaState), i);
}

inline void lua::lua_state::registerFunction(const std::string& name, lua::function func)
{
	lua_register(static_cast<lua_State*>(m_luaState), name.c_str(), (lua_CFunction) func);
}

void lua::lua_state::pcall(int32_t argumentCount, int32_t expectedReturnCount)
{
	lua_pcall(static_cast<lua_State*>(m_luaState), argumentCount, expectedReturnCount, 0);
}

inline double lua::lua_state::toNumber(int32_t i)
{
	return lua_tonumber(static_cast<lua_State*>(m_luaState), i);
}

inline int64_t lua::lua_state::toInteger(int32_t i)
{
	return lua_tointeger(static_cast<lua_State*>(m_luaState), i);
}

inline const char* lua::lua_state::toString(int32_t i)
{
	return lua_tostring(static_cast<lua_State*>(m_luaState), i);
}

inline bool lua::lua_state::toBoolean(int32_t i)
{
	return lua_toboolean(static_cast<lua_State*>(m_luaState), i);
}
