#pragma once

#include<string>

#include "DB.h"
#include "HttpServer.h"
#include "iniParser.h"

class Server {
private:
	void httpServer(tcp::acceptor& acceptor, tcp::socket& socket, DB& db);
public:
	Server(std::string ip, std::string port, DB& Database);
};


