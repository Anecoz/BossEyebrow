#include "PacketFactory.h"

#include "HelloPacket.h"

namespace boss {
namespace common {

std::unique_ptr<IPacket> PacketFactory::createFromRawData(const PacketHeader& header, std::unique_ptr<std::uint8_t[]> rawData, std::size_t rawSize)
{
  switch (header.getTypeOfPacket()) {
  case PacketType::HelloPacket:
    return std::unique_ptr<IPacket>(new HelloPacket(reinterpret_cast<char*>(rawData.get()), rawSize));
  }

  return nullptr;
}

}
}