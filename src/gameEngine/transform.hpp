#ifndef ZIPERZ_TRANSFORM_HPP
#define ZIPERZ_TRANSFORM_HPP

#include <reactphysics3d.h>

namespace zl
{
	class transform
	{
	public:
		transform() = default;
		
		void translate(rp3d::Vector3 vec);
		void rotate(rp3d::Vector3 vec);
		
		rp3d::Vector3 position;
		rp3d::Vector3 rotation;
		rp3d::Vector3 scale;
	};
}

#endif
