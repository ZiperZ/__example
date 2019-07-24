#ifndef OPENGL_SHADER_HPP
#define OPENGL_SHADER_HPP

#include <cstdint>
#include <string>

namespace gl
{
	enum class shaderType
	{
		VERTEX_SHADER,
		FRAGMENT_SHADER,
		GEOMETRY_SHADER
	};

	class shader
	{
		friend class program;
	public:
		shader() = delete;
		shader(shaderType shader_type);
		shader(const shader&)  = delete;
		shader(const shader&&) = delete;
		~shader();

		void source(const char** str, int count, const int* length);
		void compile();

		std::string compileInfo(bool justErrors);
	private:
		uint32_t m_shader;
	};
}

#endif // !OPENGL_SHADER_HPP
