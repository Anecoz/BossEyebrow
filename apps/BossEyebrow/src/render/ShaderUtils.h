#pragma once

#ifndef __APPLE__
#include <GL/glew.h>
#else
#include <OpenGL/GL3.h>
#endif

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

namespace boss {
namespace render {

class ShaderUtils {
public:
	static std::string readFile(const char* filePath);
	static GLuint loadShaders(const char *vertex_path, const char *fragment_path);
	static GLuint loadShaders(const char *vertex_path, const char *geom_path, const char *fragment_path);
};

}
}

