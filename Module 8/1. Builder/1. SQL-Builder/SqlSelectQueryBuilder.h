#pragma once

#include <string>

class SqlSelectQueryBuilder
{
private:
	std::string column{};
	std::string from{};
	std::string where{};
public:
	std::string BuildQuery();
	SqlSelectQueryBuilder& AddColumn(std::string column);
	SqlSelectQueryBuilder& AddFrom(std::string from);
	SqlSelectQueryBuilder& AddWhere(std::string column, std::string value);
};

