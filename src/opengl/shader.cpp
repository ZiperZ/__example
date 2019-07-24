#include "shader.hpp"

#include <GL/glew.h>
#include "zgl.hpp"

inline gl::shader::shader(shaderType shader_type)
{
	auto getShaderTypeFlag = [](shaderType shader_type)
	{
		GLenum lookup_table[]
		{
			GL_VERTEX_SHADER,
			GL_FRAGMENT_SHADER,
			GL_GEOMETRY_SHADER
		};

		return lookup_table[static_cast<int>(shader_type)];
	};

	m_shader = glCreateShader(getShaderTypeFlag(shader_type));
}

inline gl::shader::~shader()
{
	glDeleteShader(m_shader);
}

inline void gl::shader::source(const char** str, int count, const int* length)
{
	if (count != 0)
	{
		glShaderSource(m_shader, count, str, length);
	}
	else
	{
		throw std::exception("Shader source count must be non-zero.");
	}
}

inline void gl::shader::compile()
{
	glCompileShader(m_shader);
}

std::string gl::shader::compileInfo(bool justErrors)
{
	auto isErrorAppear = [&]() -> bool
	{
		int success;
		glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);

		return static_cast<bool>(success);
	};

	auto getInfoLog = [&]() -> std::string
	{
		auto getInfoLength = [&]()
		{
			int length;

			// Apply info length to variable length
			glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &length);

			// if info not empty
			if (length != 0)
			{
				// remove null character from length
				length--;
			}

			// return length of log
			return length;
		};

		std::string infoLog;
		infoLog.resize(getInfoLength());

		if (infoLog.size() != 0)
		{
			glGetShaderInfoLog(m_shader, (GLsizei)infoLog.size(), nullptr, &infoLog.front());

			return infoLog;
		}
		else
		{
			return {};
		}
	};

	if (justErrors)
	{
		if (!isErrorAppear())
		{
			// if no errors appear, return empty string
			return {};
		}
	}

	return getInfoLog();
}
