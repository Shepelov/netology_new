#pragma once

#include "HttpClient.h"

#include <string>
#include <vector>
#include <map>
#include <exception>

class HtmlParser
{
private:
	HttpClient* HTTP;
	std::string currentUrl;
	std::vector<std::string>urls;
	std::map<std::string, int>words;
	bool redirect{ false };

	bool isError301Or302();
	void templateErase(std::string& src, std::string start, std::string end);
	void parseUrls(std::string& src);
	void delSpaces(std::string& in, bool spaceFlag);
	void delRepeatSpaces(std::string& in);
	void parseWords(std::string& src);
	void prepareWord(std::string& in);
public:
	HtmlParser(std::string url);
	~HtmlParser();
	std::vector<std::string> getUrlsList();
	std::map<std::string, int> getWordList();
	bool isRedirect();
};

