#ifndef  ZIPERZ_OPENGL_HPP
#define ZIPERZ_OPENGL_HPP

#include <exception> // std::exception

namespace gl
{
	enum drawMode
	{
		DRAW_TRIANGLES,
		DRAW_TRIANGLE_FAN,
		DRAW_LINES,
		DRAW_LINE_STRIP,
		DRAW_LINE_LOOP,
		DRAW_POINTS
	};

	void initialize();

	void clearColor(float r, float g, float b, float a);
	void drawArrays(drawMode mode, int begin, int count);
}

#endif // ! ZIPERZ_OPENGL_HPP
