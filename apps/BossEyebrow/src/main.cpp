#include "network/NetworkManager.h"
#include "input/KeyInput.h"
#include "input/MouseButtonInput.h"
#include "input/MousePosInput.h"
#include "cards/RoomCard.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
  GLFWwindow* window;
  if (!glfwInit()) {
    return -1;
  }

  window = glfwCreateWindow(1280, 720, "BossEyebrow", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -2;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glfwSetKeyCallback(window, boss::input::KeyInput::invoke);
	glfwSetCursorPosCallback(window, boss::input::MousePosInput::invoke);
	glfwSetMouseButtonCallback(window, boss::input::MouseButtonInput::invoke);

  // TESTING
  boss::network::NetworkManager netManager;

  boss::cards::RoomCard testCard;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}