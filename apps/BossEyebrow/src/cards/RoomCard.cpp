#include "RoomCard.h"

#include "../render/Texture.h"
#include "../input/MousePosInput.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

namespace boss {
namespace cards {

RoomCard::RoomCard()
  : _damage(0)
  , _destroyable(false)
  , _highlighted(false)
  , _position({500.0, 500.0, 0.0})
  , _vao(nullptr)
  , _texture(boss::render::GraphicsUtils::loadPNGToTexture("apps/BossEyebrow/resources/cards/room/bullet_builder.png"))
  , _shader("apps/BossEyebrow/src/render/shaders/card.vert",
            "apps/BossEyebrow/src/render/shaders/card.frag")
  , _highlightShader("apps/BossEyebrow/src/render/shaders/highlight.vert",
                     "apps/BossEyebrow/src/render/shaders/highlight.frag")
{
  _vao = boss::render::GraphicsUtils::createCardMesh(_texture->getWidth(), _texture->getHeight(), 1.0f);
}

RoomCard::~RoomCard()
{}

void RoomCard::update(double delta) 
{
  _highlighted = false;
  auto mousePos = boss::input::MousePosInput::getPosition();
  mousePos.y = 720.0 - mousePos.y; // TODO Fix

  auto w = static_cast<double>(_texture->getWidth());
  auto h = static_cast<double>(_texture->getHeight());
  if (mousePos.x >= _position.x - w/2.0 &&
      mousePos.x <= _position.x + w/2.0 &&
      mousePos.y >= _position.y - h/2.0 &&
      mousePos.y <= _position.y + h/2.0) {
    _highlighted = true;
  }
}

void RoomCard::render(const boss::render::Camera& camera)
{
  auto translation = glm::translate(glm::mat4(1.0), _position);
  _vao->bind();
  if (_highlighted) {
    glDepthMask(GL_FALSE);
    auto modelMatrix = translation * glm::scale(glm::mat4(), glm::vec3(1.05, 1.05, 1.0));

    _highlightShader.bind();
    _highlightShader.uploadMatrix(camera.projection(), "projMatrix");
    _highlightShader.uploadMatrix(modelMatrix, "modelMatrix");
    _highlightShader.uploadVec(glm::vec4(1.0, 0.0, 0.0, 1.0), "highlightColor");
    _vao->draw();
    _highlightShader.unbind();
    glDepthMask(GL_TRUE);
  }
  
  _texture->bind(0);
  _shader.bind();
  _shader.uploadTexture(0, "tex");
  _shader.uploadMatrix(camera.projection(), "projMatrix");
  _shader.uploadMatrix(translation, "modelMatrix");
  _vao->draw();
  _shader.unbind();
  _texture->unbind();
  _vao->unbind();
}

}
}