#include "TCPServer.h"

#include "TCPConnection.h"

#include <functional>

namespace boss {
namespace server {

TCPServer::TCPServer()
  : _ioService()
  , _acceptor(_ioService, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 49153))
{
  startAccept();
  _ioService.run();
}

TCPServer::~TCPServer()
{
}

void TCPServer::addToQueue(std::unique_ptr<common::IPacket> packet)
{
  _queue.push(std::move(packet));
}

// TODO: Right now just writes all packets to everyone, probably not what you want in the end
void TCPServer::flush()
{
  while (!_queue.empty()) {
    std::shared_ptr<common::IPacket> packet = std::move(_queue.front());
    for (auto connection: _connections) {
      connection->writeAsync(packet);
    }
    _queue.pop();
  }
}

void TCPServer::startAccept()
{
  std::shared_ptr<common::TCPConnection> newConnection = common::TCPConnection::create(_ioService);
  _acceptor.async_accept(newConnection->socket(), std::bind(&TCPServer::handleAccept, this, newConnection, std::placeholders::_1));
}

void TCPServer::handleAccept(std::shared_ptr<common::TCPConnection> newConnection, const asio::error_code& error)
{
  if (!error) {
    _connections.push_back(newConnection);
    newConnection->start();
    startAccept();
  }
}

}
}