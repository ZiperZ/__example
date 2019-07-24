#include "program.hpp"

#include <GL/glew.h>

std::string getProgramInfo(uint32_t _program, uint32_t flag)
{
	auto getInfoLength = [&]()
	{
		int length = -1;

		// Apply info length to variable length
		glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &length);

		if (length)
		// remove null character from length
		length--;

		// return length of log
		return length;
	};

	int success;
	glGetProgramiv(_program, flag, &success);

	if (!success)
	{
		std::string log;
		log.resize(getInfoLength());

		glGetProgramInfoLog(_program, (GLsizei) log.size(), nullptr, &log.front());

		return log;
	}
	else
	{
		// return empty string
		return {};
	}
}


inline gl::program::program()
{
	m_program = glCreateProgram();
}

inline gl::program::program(const shader& vertexShader, const shader& fragmentShader)
{
	program();
	attachShader(vertexShader);
	attachShader(fragmentShader);
	link();
	validate();
}

inline gl::program::~program()
{
	glDeleteProgram(m_program);
}

inline void gl::program::attachShader(const shader& _shader)
{
	glAttachShader(m_program, _shader.m_shader);
}

inline void gl::program::link() const
{
	glLinkProgram(m_program);
}

inline void gl::program::validate() const
{
	glValidateProgram(m_program);
}

inline void gl::program::use() const
{
	glUseProgram(m_program);
}

inline std::string gl::program::linkInfo()
{
	return getProgramInfo(m_program, GL_LINK_STATUS);
}

inline std::string gl::program::validateInfo()
{
	return getProgramInfo(m_program, GL_VALIDATE_STATUS);
}

int32_t gl::program::getAttribLocation(const char* attributeName) const
{
	return glGetAttribLocation(m_program, attributeName);
}

void gl::program::uniform1f(int32_t location, float value)
{
	use();
	glUniform1f(location, value);
}

void gl::program::uniform2f(int32_t location, const glm::vec2& value)
{
	use();
	glUniform2fv(location, 1, &value[0]);
}

void gl::program::uniform3f(int32_t location, const glm::vec3& value)
{
	use();
	glUniform3fv(location, 1, &value[0]);
}

void gl::program::uniform4f(int32_t location, const glm::vec4& value)
{
	use();
	glUniform4fv(location, 1, &value[0]);
}

void gl::program::uniformMatrix2f(int32_t location, const glm::mat2& value)
{
	use();
	glUniformMatrix2fv(location, 1, GL_FALSE, &value[0][0]);
}

void gl::program::uniformMatrix3f(int32_t location, const glm::mat3& value)
{
	use();
	glUniformMatrix3fv(location, 1, GL_FALSE, &value[0][0]);
}

void gl::program::uniformMatrix4f(int32_t location, const glm::mat4& value)
{
	use();
	glUniformMatrix2fv(location, 1, GL_FALSE, &value[0][0]);
}
