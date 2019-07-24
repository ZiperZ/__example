#ifndef OGLPLUSPLUS_GLFW_WINDOW_HPP
#define OGLPLUSPLUS_GLFW_WINDOW_HPP

#include <functional>
#include <cstdint>
#include <vector>

namespace gl
{
	enum class mouseButton
	{
		MOUSE_BUTTON_LEFT,
		MOUSE_BUTTON_RIGHT,
		MOUSE_BUTTON_MIDDLE
	};

	using windowSizeCallbackFunction  = void(int, int);
	using cursorPosCallbackFunction   = void(int, int);
	// mouseButton, isRelease
	using mouseButtonCallbackFunction = void(mouseButton, bool);

	class window
	{
		friend void windowResizeHandler(void* win, int w, int h);
		friend void cursorPosHandler(void* win, double x, double y);

		using windowHandle = void*;
	public:
		window()				= delete;
		window(const window&)	= delete;
		window(uint32_t width, uint32_t height, const char* title);
		~window();

		void makeContextCurrent() const;
		void swapBuffers();

		void windowSizeCallback (std::function<windowSizeCallbackFunction>  func);
		void cursorPosCallback  (std::function<cursorPosCallbackFunction>   func);
		void mouseButtonCallback(std::function<mouseButtonCallbackFunction> func);

		std::tuple<int, int> getWindowSize();
		std::tuple<int, int> getCursorPos();

		bool isClosed() const;

		static void pollEvents();

		static void initialize();
		static void terminate();
	private:
		static void windowSizeHandler(void* win, int w, int h);
		static void cursorPosHandler(void* win, double x, double y);
		static void mouseButtonCallback(void* win, int a, int b, int c);
		static std::vector<window*> m_windows;

		std::vector<std::function<windowSizeCallbackFunction>>	 m_windowSizeFunctions;
		std::vector<std::function<cursorPosCallbackFunction>>	 m_cursorPosFunctions;
		std::vector<std::function<mouseButtonCallbackFunction>>  m_mouseButtonFunctions;

		windowHandle m_windowHandle;
	};
	/// definin' static method
	std::vector<window*> window::m_windows;
}

#endif