#ifndef ZIPERZ_OBJECT_HPP
#define ZIPERZ_OBJECT_HPP

#include "componentManager.hpp"

#include <functional>
#include <vector>

namespace zl
{
	using onDestroyFunction = void(*)(zl::object*);
	
	class object : componentManager
	{
	public:
		object() = delete;
		object(const object& obj);
		explicit object(size_t objectID, const std::string& name);
		~object();
		
		// # Returns true if objects have same properties
		bool operator==	(const object& obj);
		
		// # Duplicates object (objects gonna still keep their unique IDs)
		void operator=	(const object& obj);
		
		// # Clones object and returns pointer of new instance
		zl::object* cloneObject();
		
		// # Returns objects unique ID
		size_t getObjectID();
		void destroy();
		
		// # Contains objects position, rotation and scale
		zl::transform transform;
		
		// # Objects non-unique name
		std::string name;
	private:
		std::function<onDestroyFunction> m_onDestroyFunction;
		size_t m_objectID;
	};
}

#endif
