#pragma once

#include <glm/glm.hpp>

namespace boss {
namespace render {

class Camera
{
public:
  Camera(unsigned screenWidth, unsigned screenHeight);
  ~Camera() = default;

const glm::mat4& projection() const { return _projection; }

private:
  glm::mat4 _projection;
};

}
}