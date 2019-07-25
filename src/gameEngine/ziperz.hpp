#ifndef ZIPERZ_HPP
#define ZIPERZ_HPP

#include "object.hpp"

namespace zl
{
	namespace debug
	{
		enum class messageType
		{
			PRINT_MESSAGE,
			PRINT_WARNING,
			PRINT_ERROR
		};
		
		void printMessage	(const std::string& message, messageType type);
		void printWarning	(const std::string& message);
		void printError		(const std::string& message);
	}
	
	class gameEngine
	{
		zl::object* 	createObject();
		void 			deleteObject(const zl::object* obj);
	
		zl::object* 	findObjectByID(size_t objectID);
	
		// # Get reference to object array that created by Ziperian Library
		std::vector<zl::object>& getObjectList();
	};
}

#endif // end header guard
