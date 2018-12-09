#include "HelloPacket.h"

namespace boss {
namespace common {

HelloPacket::HelloPacket(const std::string& message)
  : _message(message)
{}

HelloPacket::~HelloPacket()
{}

const char* HelloPacket::getRawData()
{
  return _message.data();
}

std::size_t HelloPacket::getDataSize()
{
  return _message.size();
}

}
}