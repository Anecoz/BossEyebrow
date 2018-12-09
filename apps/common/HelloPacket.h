#pragma once

#include "IPacket.h"

#include <string>

namespace boss {
namespace common {

class HelloPacket : public IPacket
{
public:
  HelloPacket(const std::string& message);
  ~HelloPacket();

  virtual const char* getRawData() override;
  virtual std::size_t getDataSize() override;

private:
  std::string _message;
};

}
}