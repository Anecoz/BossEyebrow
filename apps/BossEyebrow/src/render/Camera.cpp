#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace boss {
namespace render {

Camera::Camera() 
  : _projection(glm::ortho(0.0, 100.0, 0.0, 100.0, 0.0, 100.0))
{}

}
}