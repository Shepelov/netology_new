#pragma once

#include <string>
#include <map>
#include <fstream>

class iniParser
{
public:
	iniParser(std::string filename);
	template <typename T>
	T get_value(std::string key);
	template <>
	std::string get_value(std::string key);
	template <>
	int get_value(std::string key);
	template <>
	bool get_value(std::string key);
private:
	std::map<std::string, std::string> values;
	std::string delete_spaces(std::string in, int ini_line);
	std::string not_found_message(std::string key);
};

