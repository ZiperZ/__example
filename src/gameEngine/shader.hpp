#ifndef ZIPERZ_SHADER_HPP
#define ZIPERZ_SHADER_HPP

namespace zl
{
	class shader
	{
	public:
		shader() = default;

		void createVertexShader		(const char* src);
		void createFragmentShader	(const char* src);
		void createGeometryShader	(const char* src);

		void link();
	private:
		gl::program m_program;

		gl::shader m_shaders[3]
		{
			gl::shaderType::VERTEX_SHADER,
			gl::shaderType::FRAGMENT_SHADER,
			gl::shaderType::GEOMETRY_SHADER
		};
	};
}

#endif