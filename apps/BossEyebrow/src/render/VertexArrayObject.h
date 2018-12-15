#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

#include <vector>

typedef std::vector<glm::vec3> VertVec;
typedef std::vector<unsigned> IndVec;
typedef std::vector<glm::vec3> NormalVec;

namespace boss {
namespace render {

class VertexArrayObject
{
public:
	VertexArrayObject(const VertVec& verts, const IndVec& indices, const NormalVec& normals);
	~VertexArrayObject();

	void bind();
	void unbind();
	void draw();

private:
	GLuint _vao;
	GLuint _vbo, _ibo, _nbo;

	GLuint _count;
};
}
}