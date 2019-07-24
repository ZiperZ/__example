#include "buffer.hpp"

#include <GL/glew.h>
#include <array>

inline uint32_t getBufferUsage(const gl::bufferUsage buffer_usage)
{
	static const std::array<uint32_t, 3> lookupTable
	{
		GL_STATIC_DRAW,
		GL_DYNAMIC_DRAW,
		GL_STREAM_DRAW
	};

	return lookupTable[static_cast<size_t>(buffer_usage)];
}

inline GLenum getType(gl::vertexAttribType type)
{
	static const GLenum lookup_table[]
	{
		GL_DOUBLE,
		GL_FLOAT,

		GL_UNSIGNED_BYTE,
		GL_BYTE,

		GL_UNSIGNED_SHORT,
		GL_SHORT,

		GL_UNSIGNED_INT,
		GL_INT
	};

	return lookup_table[static_cast<size_t>(type)];
}

inline gl::arrayBuffer::arrayBuffer()
{
	glGenBuffers(1, &m_buffer);
}

gl::arrayBuffer::~arrayBuffer()
{
	glDeleteBuffers(1, &m_buffer);
}

void gl::arrayBuffer::data(const void* data, size_t size, bufferUsage buffer_usage)
{
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, getBufferUsage(buffer_usage));

}

inline void gl::arrayBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
}

inline void gl::arrayBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void gl::arrayBuffer::vertexAttribPointer(uint32_t index, int32_t size, vertexAttribType type, bool normalized, int stride, void* ptr)
{
	bind();
	glVertexAttribPointer(index, size, getType(type), normalized, stride, ptr);
}

void gl::arrayBuffer::enableVertexAttribArray(uint32_t index)
{
	glEnableVertexAttribArray(index);
}
