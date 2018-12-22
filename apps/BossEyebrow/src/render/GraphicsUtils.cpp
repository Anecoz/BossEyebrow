#include "GraphicsUtils.h"

#include "lodepng.h"

#include <vector>
#include <iostream>

namespace boss {
namespace render {

Texture GraphicsUtils::loadPNGToTexture(const std::string& fileName)
{
	unsigned width, height;
	std::vector<unsigned char> image;
	unsigned error = lodepng::decode(image, width, height, fileName);

	if (error != 0) {
    std::cerr << "TEXTURE ERROR: " << error << ": " << lodepng_error_text(error) << std::endl;
    std::cerr << "File was : " << fileName << std::endl;
		return Texture();
	}
  return Texture(std::move(image), width, height);
}

}
}