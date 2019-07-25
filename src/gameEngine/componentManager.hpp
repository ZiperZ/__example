#ifndef ZIPERZ_COMPONENT_MANAGER_HPP
#define ZIPERZ_COMPONENT_MANAGER_HPP

#include "collision.hpp"
#include "mesh.hpp"

#include <vector>

namespace zl
{
	class componentManager
	{
	public:
		componentManager() = default;
	
		// # Adds new component to component array
		template<typename T>
		void createComponent();
	
		// # Removes an component from array
		template<typename T>
		void removeComponent(size_t componentID = 0);
		
		// # Returns an pointer to component
		template<typename T>
		T* getComponent(size_t componentID = 0);
		
		// # Returns an pointer to component array
		template<typename T>
		std::vector<T>* getComponentArray();
	protected:
		std::vector<mesh> 		m_mesh;
	
		std::vector<boxCollider> 	m_boxCollider;
		std::vector<boxCollider2D> 	m_boxCollider2D;
		
		std::vector<sphereCollider> m_sphereCollider;
	};
}

#endif
