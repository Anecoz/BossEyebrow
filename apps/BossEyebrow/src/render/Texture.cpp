#include "Texture.h"

namespace boss {
namespace render {

Texture::Texture()
	: _width(0)
	, _height(0)
{
}

Texture::Texture(std::vector<unsigned char>&& data, int width, int height)
	: _width(width)
	, _height(height)
{
	glGenTextures(1, &_texId);
	bind(0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);
	unbind();
}

Texture::~Texture()
{
	// TODO!
	//glDeleteTextures(1, &_texId);
}

void Texture::bind(unsigned unit)
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, _texId);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

/*void Texture::updateData(float* updatedData)
{
	bind();
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, _width, _height, GL_RED, GL_FLOAT, updatedData);
	unbind();
}*/

}
}