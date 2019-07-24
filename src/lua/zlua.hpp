#ifndef LUA_HPP
#define LUA_HPP

#include <functional>
#include <exception>
#include <string>
#include <vector>

namespace lua
{
	class lua_state;
	class exception;
	class invalidCastException;

	using function = int(*)();
}

namespace lua
{
	class exception
	{
	public:
		exception(const std::string& str) : m_info(str) {}
		~exception() = default;

		const std::string& what() { return m_info; }
	protected:
		std::string m_info;
	};

	class invalidCastException : exception
	{
	public:
		invalidCastException(const std::string& str) : exception(str) {}
	};

	class lua_state
	{
		using luaState = void*;
	public:
		lua_state();
		~lua_state();

		bool doString (const std::string& str);
		bool doFile	  (const std::string& fileName);

		void getGlobal(const std::string& name);
		void setGlobal(const std::string& name);
		void openLibs();

		void pushString (const std::string& str);
		void pushInteger(int64_t val);
		void pushNumber (double val);
		void pushTable	();

		void setField(int32_t index, const std::string& keyName);
		
		void addTableKey(int32_t index, const std::string& val,	const std::string& key);
		void addTableKey(int32_t index, double val,				const std::string& key);

		void push(const std::string& str)	{ pushString(str);	}
		void push(int64_t val)				{ pushInteger(val); }
		void push(double val)				{ pushNumber(val);	}

		void pop(int32_t count);

		bool isNumber  (int32_t i);
		bool isInteger (int32_t i);
		bool isString  (int32_t i);
		bool isTable   (int32_t i);
		bool isBoolean (int32_t i);
		bool isFunction(int32_t i);

		void pcall		(int32_t argumentCount, int32_t expectedReturnCount);
		bool getTable	(int32_t i);

		void registerFunction(const std::string& name, lua::function func);

		template<typename T>
		T get(int32_t i);

		// # Table MUST pushed before call getTableContent
		template<typename T>
		T getTableContent(const std::string& key);

		const char* toString (int32_t i);
		int64_t		toInteger(int32_t i);
		double		toNumber (int32_t i);
		bool		toBoolean(int32_t i);
//	private:
		luaState m_luaState;
	};
}

template<typename T>
T lua::lua_state::get(int32_t i)
{
	// is boolean
	if constexpr (std::is_same_v<T, bool>)
	{
		if (isBoolean(i))
			return toBoolean(i);
	}
	// is double
	else if constexpr (std::is_floating_point_v<T>)
	{
		if (isNumber(i))
			return toNumber(i);
	}
	// is integer
	else if constexpr (std::is_integral_v<T>)
	{
		if (isInteger(i))
			return toInteger(i);
	}
	else if constexpr (std::is_same_v<T, const char*> || std::is_same_v<T, std::string>)
	{
		if (isString(i))
			return static_cast<T>(toString(i));
	}

	// error string
	std::string errorMessage = "Invalid conversion: Cannot cast ";
	errorMessage.reserve(errorMessage.size() + 35);
	
	if (isInteger(i))
	{
		errorMessage += "integer";
	}
	else if (isNumber(i))
	{
		errorMessage += "number";
	}
	else if (isBoolean(i))
	{
		errorMessage += "boolean";
	}
	else if (isString(i))
	{
		errorMessage = "string";
	}
	else
	{
		errorMessage += "INVALID_TYPE";
	}
	
	errorMessage = errorMessage + " to " + typeid(T).name() + '.';
	
	throw lua::invalidCastException(errorMessage);
}

template<typename T>
T lua::lua_state::getTableContent(const std::string & key)
{
	if (isTable(-1))
	{
		// push key name
		pushstring(contentName);

		if (getTable(-2))
		{
			// possibly throw exception
			T value = get<T>(-1);

			// pop value
			pop(1);

			// return value
			return value;
		}
		else
		{
			throw std::exception("Key NOT found.");
		}
	}
	else
	{
		throw std::invalidCastException("Top of stack MUST be table.");
	}
}

#endif // !LUA_HPP
