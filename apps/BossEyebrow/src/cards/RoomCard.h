#pragma once

#include <unordered_map>

namespace boss {
namespace cards {

enum class TreasureType
{
  Thief,
  Cleric,
  Fighter,
  Scholar
};

class RoomCard
{
public:
  RoomCard();
  virtual ~RoomCard();

  unsigned treasureValue(TreasureType type) { return _treasureValues[type]; }
  unsigned damage() { return _damage; }
  bool destroyable() { return _destroyable; }

  //virtual void onHeroEnter(const Hero& hero) {}
  //virtual void onHeroDeath(const Hero& hero) {}
  //virtual void onBuilt(Decks and a command buffer?) {}
  //etc...

protected:
  unsigned _damage; // needs to be modifiable by effects
  std::unordered_map<TreasureType, unsigned> _treasureValues;
  bool _destroyable;

  // What properties can a room card have? 
  // - on build
  // - on destroy
  // - on hero enter
  // - on hero death 
  // - spell effect (i.e. destroy other room, some other effect)
  // - destroyable
  // - damage
  // - treasure type
  // - index in dungeon (place in dungeon, so that 'to the right of' kind of effects can be manageable)
};

}
}