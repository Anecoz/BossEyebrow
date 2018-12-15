#include "MouseButtonInput.h"

namespace boss {
namespace input {

bool MouseButtonInput::LEFT_DOWN = false;
bool MouseButtonInput::RIGHT_DOWN = false;
std::vector<int> MouseButtonInput::_pressed;
bool MouseButtonInput::_buttons[128];

void MouseButtonInput::invoke(GLFWwindow* window, int button, int action, int mods) {
	_buttons[button] = action != GLFW_RELEASE;

	if (action == GLFW_RELEASE && std::find(_pressed.begin(), _pressed.end(), button) != _pressed.end())
		_pressed.erase(std::remove(_pressed.begin(), _pressed.end(), button), _pressed.end());

	if (button == GLFW_MOUSE_BUTTON_1) {
		if (action == GLFW_PRESS)
			LEFT_DOWN = true;
		else if (action == GLFW_RELEASE)
			LEFT_DOWN = false;
	}
	else if (button == GLFW_MOUSE_BUTTON_2) {
		if (action == GLFW_PRESS)
			RIGHT_DOWN = true;
		else if (action == GLFW_RELEASE)
			RIGHT_DOWN = false;
	}
}
}
}