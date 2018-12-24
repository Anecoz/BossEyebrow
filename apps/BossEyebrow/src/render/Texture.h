#pragma once

#ifndef __APPLE__
#include <GL/glew.h>
#else
#include <OpenGL/GL3.h>
#endif

#include <vector>

namespace boss {
namespace render {

class Texture
{
public:
	Texture();
	Texture(std::vector<unsigned char>&& data, int width, int height);
	~Texture();

	void bind(unsigned unit);
	void unbind();

	//void updateData(float* newData);

	GLuint getId() { return _texId; }
	int getWidth() { return _width; }
	int getHeight() { return _height; }

private:
	GLuint _texId;
	int _width;
	int _height;
};
}
}