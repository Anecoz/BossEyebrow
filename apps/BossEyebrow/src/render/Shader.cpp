#include "Shader.h"
#include "ShaderUtils.h"

#ifndef __APPLE__
#include <GL/glew.h>
#else
#include <OpenGL/GL3.h>
#endif
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace boss {
namespace render {

Shader::Shader() {
	_id = -1;
}

Shader::Shader(const std::string& vertPath, const std::string& fragPath) {
	_id = ShaderUtils::loadShaders(vertPath.c_str(), fragPath.c_str());
	std::cout << "Loaded shader: " << vertPath << ", " << fragPath << std::endl;
}

Shader::Shader(const std::string& vertPath, const std::string& geomPath, const std::string& fragPath) {
	_id = ShaderUtils::loadShaders(vertPath.c_str(), geomPath.c_str(), fragPath.c_str());
	std::cout << "Loaded shader: " << vertPath << ", " << geomPath << ", " << fragPath << std::endl;
}

Shader::~Shader() {
	glDeleteProgram(_id);
}

GLuint Shader::getId() {
	return _id;
}

void Shader::bind() {
	glUseProgram(_id);
}

void Shader::unbind() {
	glUseProgram(0);
}

void Shader::uploadBool(GLboolean val, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	glUniform1i(loc, val);
}

void Shader::uploadFloat(GLfloat val, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	glUniform1f(loc, val);
}

void Shader::uploadInt(GLint val, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	glUniform1i(loc, val);
}

void Shader::uploadMatrix(const glm::mat4& mat, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	glUniformMatrix4fv(loc, 1, GL_FALSE, &mat[0][0]);
}

void Shader::uploadTexture(GLint texUnit, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	glUniform1i(loc, texUnit);
}

void Shader::uploadVec(const glm::vec2& vec, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	glUniform2fv(loc, 1, value_ptr(vec));
}

void Shader::uploadVec(const glm::vec3& vec, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	glUniform3fv(loc, 1, value_ptr(vec));
}

void Shader::uploadVec(const glm::vec4& vec, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	glUniform4fv(loc, 1, value_ptr(vec));
}

void Shader::uploadVecArr(const std::vector<glm::vec2>& arr, const std::string& name) {
	GLint loc = glGetUniformLocation(_id, name.c_str());
	GLint size = static_cast<GLint>(arr.size());
	glUniform3fv(loc, size, &arr[0].x);
}

}
}