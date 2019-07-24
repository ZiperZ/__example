#ifndef OPENGL_VERTEX_ARRAY_OBJECT_HPP
#define OPENGL_VERTEX_ARRAY_OBJECT_HPP

#include <cstdint>

namespace gl
{
	class vertexArrayObject
	{
	public:
		vertexArrayObject();
		~vertexArrayObject();

		void bind();
		static void unbind();
	private:
		uint32_t m_vao;
	};
}

#endif