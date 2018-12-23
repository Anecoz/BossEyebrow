#include "RoomCard.h"

namespace boss {
namespace cards {

RoomCard::RoomCard()
  : _damage(0)
  , _destroyable(false)
  , _position({50.0, 50.0, 1.0})
  , _texture(boss::render::GraphicsUtils::loadPNGToTexture("C:/Users/heilm/source/repos/BossEyebrow/apps/BossEyebrow/resources/cards/room/bullet_builder.png"))
{}

RoomCard::~RoomCard()
{}

}
}