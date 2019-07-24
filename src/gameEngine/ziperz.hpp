#ifndef ZIPERZ_HPP
#define ZIPERZ_HPP

#include "object.hpp"

namespace zl
{
	void createObject(const zl::object& value = {});
	void deleteObject(const zl::object& value = {});

	int  getObjectInLua();
}

#endif // end header guard