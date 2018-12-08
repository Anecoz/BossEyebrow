#include "network/NetworkManager.h"

#include <asio.hpp>
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

  // TESTING
  boss::network::NetworkManager netManager;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}