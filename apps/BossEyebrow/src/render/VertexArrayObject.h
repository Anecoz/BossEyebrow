#pragma once

#include "../Gl.h"
#include <glm/glm.hpp>

#include <vector>

typedef std::vector<glm::vec3> VertVec;
typedef std::vector<unsigned> IndVec;
typedef std::vector<glm::vec2> UvVec;

namespace boss {
namespace render {

class VertexArrayObject
{
public:
	VertexArrayObject(const VertVec& verts, const IndVec& indices, const UvVec& uvs);
	~VertexArrayObject();

	void bind();
	void unbind();
	void draw();

private:
	GLuint _vao;
	GLuint _vbo, _ibo, _tbo;

	GLuint _count;
};
}
}