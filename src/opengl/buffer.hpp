#ifndef OPENGL_BUFFER_HPP
#define OPENGL_BUFFER_HPP

#include <cstdint>

namespace gl
{
	enum class bufferUsage
	{
		STATIC_DRAW,
		DYNAMIC_DRAW,
		STREAM_DRAW
	};

	enum class vertexAttribType
	{
		TYPE_DOUBLE,
		TYPE_FLOAT,

		TYPE_UBYTE,
		TYPE_BYTE,

		TYPE_USHORT,
		TYPE_SHORT,

		TYPE_UINT,
		TYPE_INT,
	};

	class arrayBuffer
	{
	public:
		arrayBuffer();
		arrayBuffer(const arrayBuffer&)  = delete;
		arrayBuffer(const arrayBuffer&&) = delete;
		~arrayBuffer();

		void vertexAttribPointer(uint32_t index, int32_t size, vertexAttribType type, bool normalized, int stride, void* ptr);
		void enableVertexAttribArray(uint32_t index);

		void data(const void* data, size_t size, bufferUsage buffer_usage);

		void bind();
		static void unbind();
	private:
		uint32_t m_buffer = 0;
	};
}

#endif