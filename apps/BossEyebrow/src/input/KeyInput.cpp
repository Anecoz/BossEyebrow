#include "KeyInput.h"

namespace boss {
namespace input {

bool KeyInput::_keys[512];
std::vector<int>* KeyInput::_pressed = new std::vector<int>;

KeyInput::~KeyInput() {
	delete _pressed;
	_pressed = nullptr;
}

void KeyInput::invoke(GLFWwindow* window, int key, int scancode, int action, int mods) {
	_keys[key] = action != GLFW_RELEASE;
	if (action == GLFW_RELEASE && std::find(_pressed->begin(), _pressed->end(), key) != _pressed->end()) {
		_pressed->erase(std::remove(_pressed->begin(), _pressed->end(), key), _pressed->end());
	}
}
}
}