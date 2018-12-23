#pragma once

#include <glm/glm.hpp>

namespace boss {
namespace render {

class Camera
{
public:
  Camera();
  ~Camera() = default;

const glm::mat4& projection() { return _projection; }

private:
  glm::mat4 _projection;
};

}
}