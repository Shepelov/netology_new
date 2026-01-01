#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>

#include "common.hpp"
#include "DB.h"
#include "iniParser.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class HttpServer : public std::enable_shared_from_this<HttpServer> {
protected:
	tcp::socket socket;
	beast::flat_buffer buffer{ 8192 };
	http::request<http::dynamic_body> request;
	http::response<http::dynamic_body> response;
	net::steady_timer deadline{ socket.get_executor(), std::chrono::seconds(60) };

	void readRequest();
	void checkDeadline();
	void processRequest();
	void createResponseGet();
	void createResponsePost();
	void writeResponse();
	std::vector<std::string> getKeyword(const std::string& str);

private:
	DB& db;
	int amount_of_results;

	std::string urlDecode(const std::string& encoded);
public:
	HttpServer(tcp::socket socket, DB& db) : socket(std::move(socket)), db{ db } {};
	void start();
};