#include "Camera.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

namespace boss {
namespace render {

Camera::Camera(unsigned screenWidth, unsigned screenHeight) 
  : _projection(glm::ortho(0.0, static_cast<double>(screenWidth), 0.0, static_cast<double>(screenHeight), -1.0, 100.0))
{}

}
}