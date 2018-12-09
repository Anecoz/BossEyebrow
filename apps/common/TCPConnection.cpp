#include "TCPConnection.h"

#include <iostream>

namespace boss {
namespace common {

void TCPConnection::start()
{
  // Continuously start to asyncly read from socket?
  // async_read(sock, asio::buffer(buf, sizeof(packet_header)), ...
  // Then in async read handler, do asio::read for the exact number of bytes specified in header to get rest of package, then setup async_read again.
  readAsync();
}
  
void TCPConnection::writeAsync(std::shared_ptr<IPacket> packet)
{
  asio::async_write(
    _socket,
    asio::buffer(packet->getRawData(),
    packet->getDataSize()),
    std::bind(&TCPConnection::handleWrite, this, std::placeholders::_1, std::placeholders::_2));
}

void TCPConnection::handleWrite(const asio::error_code& error, std::size_t bytesTransferred)
{
  if (error) {
    std::cerr << "A connection got an error while writing a packet: " << error.message() << std::endl;
  }
  std::cout << "A connection wrote " << std::to_string(bytesTransferred) << " bytes on socket." << std::endl;
}

void TCPConnection::readAsync()
{
  asio::async_read(
    _socket,
    _readBuf.prepare(1), // SIZEOF PACKET HEADER!
    std::bind(&TCPConnection::handleReadHeader, this, std::placeholders::_1));
}

void TCPConnection::handleReadHeader(const asio::error_code& error)
{
  if (error == asio::error::eof) {
    // ok, try again
    readAsync();
    return;
  }

  if (!error) {
    _readBuf.commit(1); // SIZEOF PACKET HEADER!
    std::istream header(&_readBuf);
    std::uint8_t size;
    header >> size;

    asio::error_code packetError;
    asio::read(
      _socket,
      _readBuf.prepare(size),
      packetError);
    
    if (packetError) {
      std::cerr << "A connection received error while reading content of packet: " << packetError.message() << std::endl;
    }

    _readBuf.commit(size);

    unsigned char* output = (unsigned char*)malloc(_readBuf.size());
    _readBuf.sgetn(reinterpret_cast<char *>(output), _readBuf.size());
  }
  else {
    std::cerr << "A connection received error while reading header of packet: " << error.message() << std::endl;
  }
  readAsync();
}

}
}