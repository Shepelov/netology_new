#include "SqlSelectQueryBuilder.h"

std::string SqlSelectQueryBuilder::BuildQuery() {
	return "SELECT " + column + " FROM " + from + " WHERE " + where + ";";
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string column) {
	if (this->column.size() == 0) {
		this->column = column;
	}
	else {
		this->column = this->column + ", " + column;
	}

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string from) {
	if (this->from.empty()) {		//поле FROM заполняется один раз. Последующие попытки не изменяют значение
		this->from = from;
	}

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string column, std::string value) {
	if (this->where.empty()) {
		this->where = column + "=" + value;
	}
	else {
		this->where = this->where + " AND " + column + "=" + value;
	}

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
	for (auto pair : kv) {
		if (this->where.empty()) {
			this->where = pair.first + "=" + pair.second;
		}
		else {
			this->where = this->where + " AND " + pair.first + "=" + pair.second;
		}
	}

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {
	for (auto value : columns) {
		if (this->column.size() == 0) {
			this->column = value;
		}
		else {
			this->column = this->column + ", " + value;
		}
	}
	
	return *this;
}