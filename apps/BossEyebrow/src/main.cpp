#include "network/NetworkManager.h"
#include "input/KeyInput.h"
#include "input/MouseButtonInput.h"
#include "input/MousePosInput.h"
#include "cards/RoomCard.h"
#include "render/Camera.h"

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

  if (glewInit() != GLEW_OK) {
    glfwTerminate();
    return -3;
  }

  // TESTING
  boss::network::NetworkManager netManager;
  boss::render::Camera testCamera;
  boss::cards::RoomCard testCard;

  glDisable(GL_CULL_FACE);
  glDisable(GL_DEPTH_TEST);
  glClearColor(0.2, 0.5, 0.0, 1.0);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    testCard.render(testCamera);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}