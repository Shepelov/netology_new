#include "HttpServer.h"

void HttpServer::start() {
	readRequest();
	checkDeadline();
}

void HttpServer::readRequest() {
	//читает запросы от клиентов
	auto self = shared_from_this();
	
	http::async_read(
		socket,
		buffer,
		request,
		[self](beast::error_code ec,
			std::size_t bytes_transferred)
		{
			boost::ignore_unused(bytes_transferred);
			if (!ec)
				self->processRequest();
		});
}

void HttpServer::checkDeadline() {
	//если будут ошибки - закрывает сокет
	auto self = shared_from_this();

	deadline.async_wait(
		[self](beast::error_code ec)
		{
			if (!ec)
			{
				self->socket.close(ec);
			}
		});
}

void HttpServer::processRequest() {
	//разбираем запрос
	response.version(request.version());
	response.keep_alive(false);

	switch (request.method())
	{
	case http::verb::get:
		response.result(http::status::ok);
		response.set(http::field::server, "Beast");
		createResponseGet();//формирует ответ при get-запросе
		break;
	case http::verb::post:
		response.result(http::status::ok);
		response.set(http::field::server, "Beast");
		createResponsePost();//формирует ответ при post-запросе
		break;

	default:
		response.result(http::status::bad_request);
		response.set(http::field::content_type, "text/plain");
		//формирует ответ при неизвестном типе запроса
		beast::ostream(response.body())
			<< "Invalid request-method '"
			<< std::string(request.method_string())
			<< "'";
		break;
	}

	writeResponse();
}

void HttpServer::createResponseGet() {
	//ѕо запросу GET открываетс€ проста€ статическа€ HTML-страница с формой поиска.
	if (request.target() == "/")
	{
		response.set(http::field::content_type, "text/html");
		beast::ostream(response.body())
			<< "<html>\n"
			<< "<head><meta charset=\"UTF-8\"><title>WEB Search</title></head>\n"
			<< "<body>\n"
			<< "<center><h1>Search System</h1></center>\n"
			<< "<form action=\"/\" method=\"post\">\n"
			<< "    <label for=\"search\">Search:</label><br>\n"
			<< "    <input type=\"text\" id=\"search\" name=\"search\"><br>\n"
			<< "    <input type=\"submit\" value=\"Search\">\n"
			<< "</form>\n"
			<< "</body>\n"
			<< "</html>\n";
	}
	else
	{
		response.result(http::status::not_found);
		response.set(http::field::content_type, "text/plain");
		beast::ostream(response.body()) << "Error! Page not found!\r\n";
	}
}

void HttpServer::createResponsePost() {
	//ѕо запросу POST происходит извлечение из базы данных результата запроса и отображение веб - страницы с результатами поиска.
	if (request.target() == "/"){
		std::string s = buffers_to_string(request.body().data());
		std::cout << "POST request: " << s << std::endl;

		size_t pos = s.find('=');
		if (pos == std::string::npos){
			//если post-запрос пуст
			response.result(http::status::not_found);
			response.set(http::field::content_type, "text/plain");
			beast::ostream(response.body()) << "Error! Page not found!\r\n";
			return;
		}
		//читаем ключ и значение параметра
		std::string key = s.substr(0, pos);
		std::string value = s.substr(pos + 1);
		//русский €зык :)
		std::string utf8value = urlDecode(value);

		if (key != "search"){
			//если параметр имеет значение отличное от "search"
			response.result(http::status::not_found);
			response.set(http::field::content_type, "text/plain");
			beast::ostream(response.body()) << "File not found\r\n";
			return;
		}

		//работа с запросом
		std::vector<std::string> keywords = getKeyword(utf8value);//ищем все уникальные ключевые слова в значении параметра(они св€заны через символ ѕЋё—)

		if (keywords.size() > 0){
			std::map<std::string, int> db_result;
			for (const std::string& s : keywords){
				for (const auto& [key, value] : db.getUrl(s)){	//ищем все ссылки с ключевыми словами и суммируем их частоту вхождени€
					db_result[key] += value;
				}
			}
			if (db_result.size() > 0){
				std::multimap<int, std::string, std::greater<int>> db_result_sort;//сортируем список по убыванию частоты вхождени€
				for (const auto& [key, value] : db_result){
					db_result_sort.insert({ value, key });//формируем выходной список
				}
				response.set(http::field::content_type, "text/html");
				beast::ostream(response.body())
					<< "<html>\n"
					<< "<head><meta charset=\"UTF-8\"><title>WEB Search</title></head>\n"
					<< "<body>\n"
					<< "<center><h1>Search System</h1></center>\n"
					<< "<p>Search results:<p>\n"
					<< "<ul>\n";

				for (const auto& url : db_result_sort) {

					beast::ostream(response.body())
						<< "<li><a href=\""
						<< url.second << "\">"
						<< url.second << "</a></li>\nRelevance:"
						<< url.first << "\n\n";
				}			

				beast::ostream(response.body())
					<< "</ul>\n"
					<< "</body>\n"
					<< "</html>\n";
			}
			else{  //если нет вхождений в базе данных
				response.set(http::field::content_type, "text/html");
				beast::ostream(response.body())
					<< "<html>\n"
					<< "<head><meta charset=\"UTF-8\"><title>WEB Search</title></head>\n"
					<< "<body>\n"
					<< "<center><h1>Search System</h1></center>\n"
					<< "<p>Search results:<p>\n"
					<< "<ul>\n"
					<< "<p><b> No matches found </b></p>"
					<< "</ul>\n"
					<< "</body>\n"
					<< "</html>\n";
			}
		}
		else{ //если слов в запросе нет
			response.set(http::field::content_type, "text/html");
			beast::ostream(response.body())
				<< "<html>\n"
				<< "<head><meta charset=\"UTF-8\"><title>WEB Search</title></head>\n"
				<< "<body>\n"
				<< "<center><h1>Search System</h1></center>\n"
				<< "<p>Search results:<p>\n"
				<< "<ul>\n"
				<< "<p><b> Bad request </b></p>"
				<< "<p> The request must consist words longer than 3 characters </p>"
				<< "</ul>\n"
				<< "</body>\n"
				<< "</html>\n";
		}
	}
	else{
		response.result(http::status::not_found);
		response.set(http::field::content_type, "text/plain");
		beast::ostream(response.body()) << "File not found\r\n";
	}
}

void HttpServer::writeResponse() {
	//формирует ответ
	auto self = shared_from_this();
	response.content_length(response.body().size());

	http::async_write(
		socket,
		response,
		[self](beast::error_code ec, std::size_t){
			self->socket.shutdown(tcp::socket::shutdown_send, ec);
			self->deadline.cancel();
		});
}

std::vector<std::string> HttpServer::getKeyword(const std::string& str) {	//извлекает ключевые слова из запроса
	std::vector<std::string> result;
	std::string value = str;
	std::string::size_type pos_end = 0;
	std::string::size_type pos_begin = 0;
	do
	{
		//отдел€ем очередное слово
		pos_end = value.find('+', pos_begin);
		std::string word = value.substr(pos_begin, pos_end - pos_begin);
		if (word.length() > 3)
		{
			//ищем слово в выходном списке
			//если его нет - добавл€ем в список
			if (std::find(result.begin(), result.end(), word) == result.end())
			{
				wordToLower(word);
				result.push_back(word);
			}
		}
		pos_begin = pos_end + 1;
	} while (pos_end != std::string::npos);

	return result;
}

std::string HttpServer::urlDecode(const std::string& encoded){
	std::string res;
	std::istringstream iss(encoded);
	char ch;

	while (iss.get(ch)){
		if (ch == '%'){
			int hex;
			iss >> std::hex >> hex;
			res += static_cast<char>(hex);
		}
		else{
			res += ch;
		}
	}

	return res;
}