#pragma once
#include "../Gl.h"

#include <vector>
#include <algorithm>

namespace boss {
namespace input {

class KeyInput {
public:
	~KeyInput();

	static void invoke(GLFWwindow* window, int key, int scancode, int action, int mods);

	static bool isKeyDown(int key) {
		return _keys[key];
	}

	static bool isKeyClicked(int key) {
		if (!_keys[key])
			return false;
		if (std::find(_pressed->begin(), _pressed->end(), key) != _pressed->end())
			return false;
		_pressed->push_back(key);
		return true;
	}

private:
	static bool _keys[512];
	static std::vector<int>* _pressed;
};

}
}