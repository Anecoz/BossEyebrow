#pragma once

#include <GLFW/glfw3.h>

#include <algorithm>
#include <vector>

namespace boss {
namespace input {

class MouseButtonInput {
public:

	static void invoke(GLFWwindow* window, int button, int action, int mods);

	static bool isMouseLeftDown() { return LEFT_DOWN; }
	static bool isMouseRightDown() { return RIGHT_DOWN; }

	static bool isMouseButtonClicked(int button) {
		if (!_buttons[button])
			return false;
		if (std::find(_pressed.begin(), _pressed.end(), button) != _pressed.end())
			return false;
		_pressed.push_back(button);
		return true;
	}
private:

	static bool LEFT_DOWN;
	static bool RIGHT_DOWN;
	static std::vector<int> _pressed;
	static bool _buttons[128];
};

}
}