#ifndef ZIPERZ_TRANSFORM_HPP
#define ZIPERZ_TRANSFORM_HPP

#include <glm/glm.hpp>

namespace zl
{
	using position	= glm::vec3;
	using rotation	= glm::vec3;
	using scale		= glm::vec3;
	
	class transform
	{
	public:
		position	position;
		rotation	rotation;
		scale		scale;
	};
}

#endif