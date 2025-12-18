#pragma once

#include <pqxx/pqxx>
#include <iostream>



class DB
{
private:
	pqxx::connection* conn;
public:
	DB(bool erase);
	~DB();
	void addEntry(std::string url, std::string word, int amount);
};

