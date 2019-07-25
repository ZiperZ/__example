#ifndef ZIPERZ_COLLISION_HPP
#define ZIPERZ_COLLISION_HPP

#include "reactphysics3d.h"

namespace zl
{
	class boxCollider
	{
	public:
		boxCollider() = delete;
		
		// # Argumets are half extends of collider
		explicit boxCollider(float x, float y, float z);
	protected:
	};

	class boxCollider2d : boxCollider
	{
	  public:
	  	boxCollider2d() = delete;
		
		// # Arguments are half extends of collider
		explicit boxCollider2d(float x, float y) { boxCollider::boxCollider(x, y, 0.0f); }
	};
	
	class sphereCollider
	{
	public:
		sphereCollider() = delete;
		
		explicit sphereCollider(float radius);
	protected:
	};
}

#endif // end header guard
