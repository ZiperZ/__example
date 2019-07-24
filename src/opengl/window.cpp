#include "window.hpp"

#include "zgl.hpp"
#include <glfw/glfw3.h>

void gl::window::windowSizeHandler(void* win, int w, int h)
{
	for (auto i : m_windows)
	{
		if (i->m_windowHandle == win)
		{
			for (auto& func : i->m_windowSizeFunctions)
			{
				func(w, h);
			}
			break;
		}
	}
}

void gl::window::cursorPosHandler(void* win, double x, double y)
{
	for (auto i : m_windows)
	{
		if (i->m_windowHandle == win)
		{
			for (auto& func : i->m_cursorPosFunctions)
			{
				func(static_cast<int>(x), static_cast<int>(y));
			}
			break;
		}
	}
}

void gl::window::mouseButtonCallback(void* win, int a, int b, int c)
{
	for (auto i : m_windows)
	{
		if (i->m_windowHandle == win)
		{
			for (auto& func : i->m_mouseButtonFunctions)
			{
				func(static_cast<mouseButton>(a), static_cast<bool>(b == GLFW_RELEASE));
			}
			break;
		}
	}
}

inline void gl::window::initialize()
{
	if (glfwInit() != GLFW_TRUE)
	{
		throw std::exception("OpenGL window system initialization failed.");
	}
}

inline void gl::window::terminate()
{
	glfwTerminate();
}

inline gl::window::window(uint32_t width, uint32_t height, const char* title)
{
	// create window
	m_windowHandle = static_cast<windowHandle>(glfwCreateWindow(width, height, title, nullptr, nullptr));

	// if window handle is valid
	if (m_windowHandle != nullptr)
	{
		m_windows.push_back(this);
	}
	else
	{
		throw std::exception("Cannot create window.");
	}

	glfwSetWindowSizeCallback(static_cast<GLFWwindow*>(m_windowHandle), (GLFWwindowsizefun) windowSizeHandler);
	glfwSetCursorPosCallback (static_cast<GLFWwindow*>(m_windowHandle), (GLFWcursorposfun)  cursorPosHandler);
}

inline gl::window::~window()
{
	// destroy window handle
	glfwDestroyWindow(static_cast<GLFWwindow*>(m_windowHandle));

	// remove this window from list
	m_windows.erase(m_windows.begin());
}

inline bool gl::window::isClosed() const
{
	return glfwWindowShouldClose(static_cast<GLFWwindow*>(m_windowHandle));
}

inline void gl::window::makeContextCurrent() const
{
	glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_windowHandle));
}

inline void gl::window::swapBuffers()
{
	glfwSwapBuffers(static_cast<GLFWwindow*>(m_windowHandle));
}

void gl::window::windowSizeCallback(std::function<windowSizeCallbackFunction> func)
{
	m_windowSizeFunctions.push_back(func);
}

void gl::window::cursorPosCallback(std::function<cursorPosCallbackFunction> func)
{
	m_cursorPosFunctions.push_back(func);
}

void gl::window::mouseButtonCallback(std::function<mouseButtonCallbackFunction> func)
{
	m_mouseButtonFunctions.push_back(func);
}

std::tuple<int, int> gl::window::getWindowSize()
{
	int w, h;
	glfwGetWindowSize(static_cast<GLFWwindow*>(m_windowHandle), &w, &h);

	return std::make_tuple(w, h);
}

std::tuple<int, int> gl::window::getCursorPos()
{
	double x, y;

	glfwGetCursorPos(static_cast<GLFWwindow*>(m_windowHandle), &x, &y);

	return std::make_tuple(static_cast<int>(x), static_cast<int>(y));
}

inline void gl::window::pollEvents()
{
	glfwPollEvents();
}