#pragma once
#pragma comment(lib, "pqxx/pq.lib")
#pragma comment(lib, "pqxx/pqxx.lib")

#include <pqxx/pqxx>
#include <iostream>
#include <map>

class DB
{
private:
	pqxx::connection* conn;

	bool isUrlExists(std::string url, pqxx::work* tx);
	bool isWordExists(std::string word, pqxx::work* tx);
public:
	DB(std::string host, std::string port, std::string dbname, std::string user, std::string password, bool erase);
	~DB();
	void addEntry(std::string url, std::string word, int amount);
	std::map<std::string, int> getUrl(const std::string& keyword);
	bool isUrlExists(std::string url);
};

