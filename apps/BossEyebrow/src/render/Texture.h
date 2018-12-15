#pragma once

#include <GL/glew.h>

#include <vector>

namespace boss {
namespace render {

class Texture
{
public:
	Texture();
	Texture(std::vector<unsigned char>&& data, int width, int height);
	~Texture();

	void bind();
	void unbind();

	//void updateData(float* newData);

	GLuint getId() { return _texId; }

private:
	GLuint _texId;
	int _width;
	int _height;
};
}
}