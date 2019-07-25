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
		boxCollider(float x, float y, float z);
	
	private:
	};

	class boxCollider2d : boxCollider
	{
	  public:
	  	boxCollider2d() = delete;
		
		// # Argumets are half extends of collider
		boxCollider2d(float x, float y) { boxCollider::boxCollider(x, y, 0.0f); }
	  
	  private:
	};
	
	class sphereCollider
	{
	public:
		sphereCollider() = delete;
		
		sphereCollider(float radius);
	private:
	};
}

#endif // end header guard
