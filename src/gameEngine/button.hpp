#ifndef ZIPERZ_BUTTON_HPP
#define ZIPERZ_BUTTON_HPP

#include <opengl/window.hpp>

#include <functional>
#include <vector>

namespace zl
{
	class button
	{
		friend bool isPointerColliding(const button& _button, float x, float y);
		static std::vector<button&> m_buttons;
	public:
		button(gl::window* win, float x, float y, float width, float height);
		
		void update();
	private:
		gl::window* m_window;

		float x;
		float y;

		bool m_isInsideButton;
		
		std::function<void> m_onPointerEnterFunction;
		std::function<void> m_onPointerExitFunction;

		std::function<void> m_onClickFunction;
		std::function<void> m_onReleaseFunction;
	};
}

#endif