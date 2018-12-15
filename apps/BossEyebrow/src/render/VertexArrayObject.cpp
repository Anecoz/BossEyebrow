#include "VertexArrayObject.h"

namespace boss {
namespace render {

VertexArrayObject::VertexArrayObject(const VertVec& verts, const IndVec& indices, const NormalVec& normals) {
	_count = static_cast<GLuint>(indices.size());
	glGenVertexArrays(1, &_vao);
	glGenBuffers(1, &_vbo);
	glGenBuffers(1, &_ibo);
	glGenBuffers(1, &_nbo);

	bind();

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, _nbo);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned), &indices[0], GL_STATIC_DRAW);
	
	unbind();
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

VertexArrayObject::~VertexArrayObject() {
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_ibo);
	glDeleteBuffers(1, &_nbo);
	glDeleteVertexArrays(1, &_vao);
}

void VertexArrayObject::bind() {
	glBindVertexArray(_vao);
}

void VertexArrayObject::unbind() {
	glBindVertexArray(0);
}

void VertexArrayObject::draw() {
	bind();
	glDrawElements(GL_TRIANGLES, _count, GL_UNSIGNED_INT, 0L);
	unbind();
}
}
}