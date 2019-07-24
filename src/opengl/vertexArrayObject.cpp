#include "vertexArrayObject.hpp"

#include <GL/glew.h>

inline gl::vertexArrayObject::vertexArrayObject()
{
	glGenVertexArrays(1, &m_vao);
}

inline gl::vertexArrayObject::~vertexArrayObject()
{
	glDeleteVertexArrays(1, &m_vao);
}

inline void gl::vertexArrayObject::bind()
{
	glBindVertexArray(m_vao);
}

inline void gl::vertexArrayObject::unbind()
{
	glBindVertexArray(0);
}
