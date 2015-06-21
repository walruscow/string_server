#pragma once

#include <functional>
#include <string>
#include <sstream>

class Connection {
 public:
  Connection() : socket(0) {}
  Connection(int socket_) : socket(socket_) {}
  // Return negative on error; positive on done; 0 on not done
  int read(std::string& result);
  int recv(std::string& result);
  // Return negative on error; 0 on success. Blocks.
  int send(const std::string& reply);
  void close();

  int socket;

 private:
  std::stringstream ss;
  uint32_t messageLength = 0;
  uint32_t bytesRead = 0;

  int doRead(std::string& result,
             const std::function<ssize_t(int, char*, size_t)>& reader);
};