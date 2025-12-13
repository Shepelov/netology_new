#include "HttpClient.h"

HttpClient::HttpClient(std::string url) {
    parseUrl(url);
    
    net::io_context ioc;

    //создаем и настраиваем ssl
    ssl::context ctx{ wintls::method::system_default };
    ctx.use_default_certificates(true);
    ctx.verify_server_certificate(true);
    ssl::stream<beast::tcp_stream> stream(ioc, ctx);
    stream.set_server_hostname(host);
    stream.set_certificate_revocation_check(true);

    //получаем ip
    tcp::resolver resolver(ioc);
    auto const results = resolver.resolve(host, "443");

    //устанавливаем соединение
    beast::get_lowest_layer(stream).connect(results);
    stream.handshake(wintls::handshake_type::client);

    //отправляем GET-запрос
    http::request<http::string_body> req{ http::verb::get, target, 11 };
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    http::write(stream, req);

    //читаем ответ сервера
    beast::flat_buffer buffer;
    http::read(stream, buffer, res); //ошибка при использовании редиректа возникает тут!

    //завершаем соединение
    stream.shutdown();
}

HttpClient::~HttpClient() {

}

void HttpClient::parseUrl(std::string url) { //разбор поданного URL на составные части
    //если есть название протокола - отбрасываем его
    if (url.find("//") != std::string::npos) {
        url.erase(0, url.find("//") + 2);
    }

    host = url.substr(0, url.find("/"));
    target = url.substr(url.find("/"), std::string::npos);
    //std::cout << "\"" << host << "\"" << std::endl;
}

std::string HttpClient::getBase() { //получение всего содержимого 
    std::string result = boost::lexical_cast<std::string>(res.base());
   return std::move(result);
}

std::string HttpClient::getBody() { //получение только <body> </body>
    std::string result = boost::lexical_cast<std::string>(res.body());
    return std::move(result);
}