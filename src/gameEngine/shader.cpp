#include "shader.hpp"

void zl::shader::createVertexShader(const char* src)
{
	m_shaders[0].source(src);
	m_shaders[0].compile();
	m_program.attachShader(m_shaders[0]);
}

void zl::shader::createFragmentShader(const char* src)
{
	m_shaders[1].source(src);
	m_shaders[1].compile();
	m_program.attachShader(m_shaders[1]);
}

void zl::shader::createGeometryShader(const char* src)
{
	m_shaders[2].source(src);
	m_shaders[2].compile();
	m_program.attachShader(m_shaders[2]);
}
