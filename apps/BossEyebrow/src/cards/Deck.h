#pragma once

#include "RoomCard.h"

#include <memory>
#include <vector>

namespace boss {
namespace cards {

class Deck
{
public:
  Deck();
  ~Deck();

private:
  std::vector<std::unique_ptr<RoomCard>> _cards;
};

}
}