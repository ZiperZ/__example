#ifndef OPENGL_PROGRAM_HPP
#define OPENGL_PROGRAM_HPP

#include "shader.hpp"

#include <glm/glm.hpp>
#include <string>

namespace gl
{
	class program
	{
	public:
		program();
		program(const shader& vertexShader, const shader& fragmentShader);
		~program();

		void attachShader(const shader& _shader);

		void link()		const;
		void validate() const;

		void use() const;

		std::string linkInfo();
		std::string validateInfo();

		int32_t getAttribLocation(const char* attributeName) const;

		void uniform1f(int32_t location, float value);
		void uniform2f(int32_t location, const glm::vec2& value);
		void uniform3f(int32_t location, const glm::vec3& value);
		void uniform4f(int32_t location, const glm::vec4& value);

		void uniformMatrix2f(int32_t location, const glm::mat2& value);
		void uniformMatrix3f(int32_t location, const glm::mat3& value);
		void uniformMatrix4f(int32_t location, const glm::mat4& value);
	private:
		uint32_t m_program;
	};
}

#endif // !OPENGL_PROGRAM_HPP
