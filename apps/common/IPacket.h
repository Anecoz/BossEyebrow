#pragma once

#include <cstddef>

namespace boss {
namespace common {

// TODO: Headers so that packets can be distinguished from one another
// TODO: Some way to construct a correct packet using raw data (on receiver side), probably reading header 
class IPacket
{
public:
  virtual const char* getRawData() = 0;
  virtual std::size_t getDataSize() = 0;
};

}
}