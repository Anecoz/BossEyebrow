#include "network/NetworkManager.h"
#include "input/KeyInput.h"
#include "input/MouseButtonInput.h"
#include "input/MousePosInput.h"
#include "cards/RoomCard.h"
#include "render/Camera.h"

#include "Gl.h"
#include <iostream>

int main()
{
  GLFWwindow* window;
  if (!glfwInit()) {
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

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

#ifndef __APPLE__
  if (glewInit() != GLEW_OK) {
    glfwTerminate();
    return -3;
  }
#endif

  std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
  std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "Supported OpenGL version: " << glGetString(GL_VERSION) << std::endl;

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