#include "button.hpp"

#include <glfw/glfw3.h>

bool zl::isPointerColliding(const button& _button, float x, float y)
{
	// convert y to OpenGL Normalized Device Coordinates
	y = 1.0 - y;

	return (_button.x < x && _button.y < y);
}

inline zl::button::button(gl::window* win, float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;

	auto mousePos = win->getCursorPos();

	m_isInsideButton = isColliding(*this, std::get<0>(mousePos), std::get<1>(mousePos));
}