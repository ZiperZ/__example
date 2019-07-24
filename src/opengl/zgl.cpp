#include "zgl.hpp"

#include <GL/glew.h>

void gl::initialize()
{
	static bool isInitialized = false;

	if (!isInitialized)
	{
		switch (glewInit())
		{
		case GLEW_OK:
			break;
		default:
			throw std::exception("Error niggi");
		}

		isInitialized = true;
	}
}

void gl::clearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

inline void gl::drawArrays(drawMode mode, int begin, int count)
{
	auto getDrawModeFlag = [](drawMode mode)
	{
		static const GLenum lookup_table[]
		{
			GL_TRIANGLES,
			GL_TRIANGLE_FAN,
			GL_LINES,
			GL_LINE_STRIP,
			GL_LINE_LOOP,
			GL_POINTS
		};

		return lookup_table[static_cast<int>(mode)];
	};

	glDrawArrays(getDrawModeFlag(mode), begin, count);
}
