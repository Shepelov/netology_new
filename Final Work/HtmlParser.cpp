#include "HtmlParser.h"
#include "common.hpp"

HtmlParser::HtmlParser(std::string url) {
	currentUrl = url;
	try {
		HTTP = new HttpClient(url);	//пробуем запустить http-клиент с переданным url-адресом
	}
	catch (std::exception e) {		//отлавливаем любые ошибки при работе клиента
		return;						//если ошибка возникла - передаем управление обратно вызвавшей функции
	}
	std::string res = HTTP->getBody();
	if (!this->isError301Or302()) {
		templateErase(res, "<head>", "</head>");	//удаляем блок head
		templateErase(res, "<!--", "-->");	//удаляем комментарии
		templateErase(res, "<script", "</script>");	//удаляем скрипты
		templateErase(res, "<style", "</style>");	//удаляем блоки style
		parseUrls(res); //парсим ссылки
		templateErase(res, "<", ">");	//удаляем оставшиеся теги
		delSpaces(res, false); //удаляем табуляцию и знаки переноса
		templateErase(res, "&", ";"); //удаляем специальные символы типа &nbsp; и пр.
		delRepeatSpaces(res); //удаляем лишние (повторяющиеся) пробелы
		parseWords(res);
	}
	delete HTTP;
}

HtmlParser::~HtmlParser() {

}

bool HtmlParser::isError301Or302() {	//проверка на ошибки 301 и 302
	std::string base = HTTP->getBase();
	if (base.find("HTTP/1.1 301 Moved Permanently") != std::string::npos || 
		base.find("HTTP/1.1 302 Moved temporarily") != std::string::npos) {
		redirect = true;
		//вытащим редирект
		base = base.substr(base.find("Location: ") + 10, base.find('\n', base.find("Location: ")) - base.find("Location: ") - 11);
		urls.push_back(base); //запишем редирект в пул ссылок
		return true;
	}
	else {
		return false;
	}
}

void HtmlParser::templateErase(std::string& src, std::string start, std::string end) {	//удаление подстроки по шаблону
	while (src.find(start) != std::string::npos && src.find(end) != std::string::npos){
			src.replace(src.find(start), src.find(end) - src.find(start) + end.size(), " "); //вместо подстроки вставляем пробел
		}
}

void HtmlParser::parseUrls(std::string& src) {
	std::string start = "<a href=\"";
	std::string end = "\"";	//конец url в ссылке
	std::string tagEnd = ">";	//конец открывающего тега <a href>
	while (src.find(start) != std::string::npos && src.find(end, src.find(start) + start.size()) != std::string::npos) {
		std::string result = src.substr(src.find(start) + start.size(), src.find(end, src.find(start) + start.size()) - src.find(start) - start.size());
		src.replace(src.find(start), src.find(tagEnd, src.find(start)) - src.find(start) + tagEnd.size(), " ");
		
		//удаляем из result лишние пробелы, знаки табуляции и \n
		delSpaces(result, true);

		//если то что передано в result не является ссылкой на страницу - отсекаем результат
		if (result.substr(0, 11) == "javascript:" ||
			result.substr(0, 7) == "mailto:" ||
			result.substr(0, 1) == "#" || //якоря тоже не вносим в очередь
			result == "" ||
			result == currentUrl ||
			result == "/") { //ссылки на себя тоже не вносим в очередь
			continue;
		}

		//если ссылка начинается с символа '/' - добавляем к ней имя сайта для последующего корректного использования Http-клиентом
		if (result[0] == '/') {
			result = currentUrl + result.erase(0, 1);
		}

		//записываем ссылку в очередь
		urls.push_back(result);	//импровизированная очередь
	}
}

void HtmlParser::delSpaces(std::string& in, bool spaceFlag) {	//удаляет из входной строки пробелы (если установлен флаг), \t, \n
	std::string out;
	for (int i = 0; i < in.size(); ++i) {
		if (in[i] == '\n' || in[i] == '\t') {
			continue;
		}
		else if (in[i] == ' ' && spaceFlag) {
			continue;
		}
		out += in[i];
	}
	in = out;
}

void HtmlParser::delRepeatSpaces(std::string& in) {
	std::string out;
	for (int i = 0; i < in.size(); ++i) {
		if (in[i] == ' ' && i != in.size() && in[i] == in[i + 1]) {
			continue;
		}
		out += in[i];
	}
	in = out;
}

void HtmlParser::parseWords(std::string& src) { //парсим слова в вектор
	while (src.size() > 0) {
		if (src[0] == ' ') {
			src.erase(0, 1);
		}
		else {
			std::string word;
			word = src.substr(0, src.find(' '));
			prepareWord(word);
			if (word.size() > 6) {		//выбираем слова больше 3 символов (символ кириллицы имеет размер 2)
				if (words.find(word) == words.end()) {	//если в мапе не найдено данное слово
					words.insert({ word, 1 });	//добавляем его с индексом 1
				}
				else {	//если найдено
					words[word]++;	//увеличиваем значение на 1
				}
			}
			src.erase(0, src.find(' '));
		}
	}
}

void HtmlParser::prepareWord(std::string& in) {	//оставляет в слове только буквы + приводит их к нижнему регистру
	std::string out = in;
	wordToLower(out);	//приводим к нижнему регистру
	in = out;
}

std::vector<std::string> HtmlParser::getUrlsList() {
	return urls;
}

std::map<std::string, int> HtmlParser::getWordList() {
	return words;
}
bool HtmlParser::isRedirect() {
	return redirect;
}