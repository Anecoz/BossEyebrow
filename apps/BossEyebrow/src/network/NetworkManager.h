#pragma once

#include <asio.hpp>

namespace boss {
namespace network {

class NetworkManager
{
public:
  NetworkManager();
  ~NetworkManager();

private:
  asio::io_service _ioService;
};

}
}