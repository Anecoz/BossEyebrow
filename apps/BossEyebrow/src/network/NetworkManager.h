#pragma once

#include "TCPConnection.h"

#include <asio.hpp>

#include <memory>

namespace boss {
namespace network {

class NetworkManager
{
public:
  NetworkManager();
  ~NetworkManager();

private:
  //asio::ip::tcp::resolver _resolver;
  //asio::io_service _ioService;

  std::shared_ptr<common::TCPConnection> _connection;
};

}
}