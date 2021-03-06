#pragma once
#include "../Gl.h"
#include <glm/glm.hpp>

namespace boss {
namespace input {

class MousePosInput {
public:
	static glm::vec2 getPosition() { return glm::vec2(_x, _y); }

	static void invoke(GLFWwindow* window, double xPos, double yPos);

private:
	static double _x;
	static double _y;
};

}
}