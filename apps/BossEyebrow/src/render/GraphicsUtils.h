#pragma once

#include "Texture.h"

#include <GL/glew.h>

#include <string>

namespace boss {
namespace render {

class GraphicsUtils {
public:
	static Texture loadPNGToTexture(const std::string& fileName);
};

}
}


