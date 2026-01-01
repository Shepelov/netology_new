#include "Server.h"

Server::Server(std::string ip, std::string port, DB& Database) {
	try
	{
		unsigned short us_port = static_cast<unsigned short>(std::stoi(port));
		auto const address = net::ip::make_address(ip);

		//запускаем сервер
		net::io_context ioc{ 1 };

		tcp::acceptor acceptor{ ioc, { address, us_port } };
		tcp::socket socket{ ioc };
		httpServer(acceptor, socket, Database);

		std::cout << "Server was started on http://localhost:" << port << ".\nPlease, visit this page in your favorite browser to use Search System" << std::endl;

		ioc.run();
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void Server::httpServer(tcp::acceptor& acceptor, tcp::socket& socket, DB& db){
	acceptor.async_accept(socket,
		[&](beast::error_code ec)
		{
			if (!ec)
				std::make_shared<HttpServer>(std::move(socket), db)->start();
			httpServer(acceptor, socket, db);
		});
}