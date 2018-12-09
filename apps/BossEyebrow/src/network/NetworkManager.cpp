#include "NetworkManager.h"

#include <iostream>

namespace boss {
namespace network {

NetworkManager::NetworkManager()
  : _ioService()
  , _resolver(_ioService)
  , _connection(common::TCPConnection::create(_ioService))
{
  try {
    _connection = common::TCPConnection::create(_ioService);

    std::cout << "Attempt to connect to server...";

    asio::ip::tcp::resolver::query query("localhost", "49153");
    asio::ip::tcp::resolver::iterator endpointIterator = _resolver.resolve(query);

    asio::connect(_connection->socket(), endpointIterator);
    std::cout << "Connected to server!" << std::endl;
  }
  catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}

NetworkManager::~NetworkManager()
{}

}
}