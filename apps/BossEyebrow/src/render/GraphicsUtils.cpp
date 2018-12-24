#include "GraphicsUtils.h"
#include "lodepng.h"

#include <vector>
#include <iostream>

namespace boss {
namespace render {

std::unique_ptr<Texture> GraphicsUtils::loadPNGToTexture(const std::string& fileName)
{
	unsigned width, height;
	std::vector<unsigned char> image;
	unsigned error = lodepng::decode(image, width, height, fileName);

	if (error != 0) {
    std::cerr << "TEXTURE ERROR: " << error << ": " << lodepng_error_text(error) << std::endl;
    std::cerr << "File was : " << fileName << std::endl;
		return nullptr;
	}
  return std::make_unique<Texture>(std::move(image), width, height);
}

std::unique_ptr<VertexArrayObject> GraphicsUtils::createCardMesh(float width, float height, float layer)
{
	VertVec verts = {
		{-width/2.0, height/2.0, layer},
		{-width/2.0, -height/2.0, layer},
		{width/2.0, -height/2.0, layer},
		{width/2.0, height/2.0, layer}
	};

	UvVec uvs = {
		{0.0f, 0.0f},
		{0.0f, 1.0f},
		{1.0f, 1.0f},
		{1.0f, 0.0f}
	};

	IndVec indices = {0, 1, 3, 3, 1, 2};

	return std::make_unique<VertexArrayObject>(verts, indices, uvs);
}

}
}