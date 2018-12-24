#include "RoomCard.h"

#include "../render/Texture.h"

#include <glm/gtc/matrix_transform.hpp>

namespace boss {
namespace cards {

RoomCard::RoomCard()
  : _damage(0)
  , _destroyable(false)
  , _position({50.0, 50.0, 0.0})
  , _vao(boss::render::GraphicsUtils::createCardMesh(10.0f, 10.0f, 1.0f))
  , _texture(boss::render::GraphicsUtils::loadPNGToTexture("apps/BossEyebrow/resources/cards/room/bullet_builder.png"))
  , _shader("apps/BossEyebrow/src/render/shaders/card.vert",
            "apps/BossEyebrow/src/render/shaders/card.frag")
{}

RoomCard::~RoomCard()
{}

void RoomCard::render(const boss::render::Camera& camera)
{
  _vao->bind();
  _texture->bind(0);
  _shader.bind();
  _shader.uploadTexture(0, "tex");
  _shader.uploadMatrix(camera.projection(), "projMatrix");
  _shader.uploadMatrix(glm::translate(glm::mat4(), _position), "modelMatrix");
  _vao->draw();
  _shader.unbind();
  _texture->unbind();
  _vao->unbind();
}

}
}