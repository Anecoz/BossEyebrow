#pragma once

#include "Texture.h"
#include "VertexArrayObject.h"

#include <GL/glew.h>

#include <string>
#include <memory>

namespace boss {
namespace render {

class GraphicsUtils {
public:
	static std::unique_ptr<Texture> loadPNGToTexture(const std::string& fileName);
	static std::unique_ptr<VertexArrayObject> createCardMesh(float width, float height, float layer);
};

}
}


