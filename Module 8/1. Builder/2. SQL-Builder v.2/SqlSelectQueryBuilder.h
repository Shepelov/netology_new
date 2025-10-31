#pragma once

#include <string>
#include <map>
#include <vector>

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
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
};

