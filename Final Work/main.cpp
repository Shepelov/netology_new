#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <wintls.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = wintls;
//namespace ssl = boost::asio::ssl;
namespace ip = net::ip;
using tcp = ip::tcp;

//HTTP-клиент
int main2()
{
    std::string host = "www.iana.org";
    std::string port = "80";
    std::string query = "/";

    net::io_context ioc;

    tcp::resolver resolver{ ioc };
    beast::tcp_stream stream{ ioc };
    auto const results = resolver.resolve(host, port);
    stream.connect(results);

    //отправляем get-запрос
    http::request<http::string_body> req{ http::verb::get, query, 11 };
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    http::write(stream, req);

    // читаем ответ
    beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;
    http::read(stream, buffer, res);

    //выводим ответ
    std::cout << boost::beast::buffers_to_string(res.body().data());

    return 0;
}



//HTTPS-клиент
int main(){
    std::string host = "gismeteo.ru";
    std::string port = "443";
    std::string query = "/";

    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ wintls::method::system_default };

    // Use the operating systems default certificates for verification
    ctx.use_default_certificates(true);

    // Verify the remote server's certificate
    ctx.verify_server_certificate(true);

    // Construct the TLS stream with the parameters from the context
    ssl::stream<beast::tcp_stream> stream(ioc, ctx);

    // Set SNI hostname (many hosts need this to handshake successfully)
    stream.set_server_hostname(host);

    // Enable Check whether the Server Certificate was revoked
    stream.set_certificate_revocation_check(true);

    // Look up the domain name
    tcp::resolver resolver(ioc);
    auto const results = resolver.resolve(host, port);

    // Make the connection on the IP address we get from a lookup
    beast::get_lowest_layer(stream).connect(results);

    // Perform the TLS handshake
    stream.handshake(wintls::handshake_type::client);

    // Set up an HTTP GET request message
    http::request<http::string_body> req{ http::verb::get, query, 11 };
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Send the HTTP request to the remote host
    http::write(stream, req);

    // This buffer is used for reading and must be persisted
    beast::flat_buffer buffer;

    // Declare a container to hold the response
    http::response<http::dynamic_body> res;

    // Receive the HTTP response
    http::read(stream, buffer, res);

    // Write the message to standard out
    std::cout << res << std::endl;

    // Shutdown the TLS connection
    stream.shutdown();
}