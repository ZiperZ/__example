#ifndef ZIPERZ_RENDERER_HPP
#define ZIPERZ_RENDERER_HPP

#include <string>

namespace zl
{
	class renderer
	{
	public:
		renderer() = default;

		void loadFile(const std::string& fileName);
		void loadRawData(float* arr, size_t count);
	private:
	};
}

#endif