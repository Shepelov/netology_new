#define _CRT_SECURE_NO_WARNINGS

#pragma once
#pragma comment(lib, "openssl/libcrypto.lib")
#pragma comment(lib, "openssl/libssl.lib")

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/lexical_cast.hpp>
#include <wintls.hpp>
#include <iostream>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = wintls;
namespace ip = net::ip;
using tcp = ip::tcp;

class HttpClient
{
private:
    std::string host;
    std::string target;
    http::response<http::string_body> res;

    void parseUrl(std::string url);
public:
    HttpClient(std::string url);
    ~HttpClient();
    std::string getBase();
    std::string getBody();
};

