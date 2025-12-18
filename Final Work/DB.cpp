#include "DB.h"

DB::DB(bool erase) {
	try {
		this->conn = new pqxx::connection(
			"host=localhost "
			"port=5432 "
			"dbname=postgres "
			"user=postgres "
			"password=1989 ");
	}
	catch (std::exception e) {
		std::cout << "DB connection error!" << std::endl;
		return;
	}

	if (erase) {	//если установлен флаг выполняем удаление таблицы с данными перед началом работы паука
		pqxx::work tx{ *conn };
		tx.exec(
			"DROP TABLE IF EXISTS _spider;"
		);
		tx.commit();
	}
	//создание таблицы для паука
	pqxx::work tx{ *conn };
	tx.exec(
		"CREATE TABLE IF NOT EXISTS _spider("
		"url VARCHAR(400) NOT NULL, " //url может быть достаточно длинным, поэтому отводим под него большую строку
		"word VARCHAR(40) NOT NULL, "
		"amount INTEGER NOT NULL, "
		"UNIQUE (url, word)"
		");"
	);
	tx.commit();
}

DB::~DB() {
	conn->close();
}

void DB::addEntry(std::string url, std::string word, int amount) {
	pqxx::work tx{ *conn };
	tx.exec(
		"INSERT INTO _spyder values('"
		+ word +
		"', '"
		+ url +
		"', "
		+ std::to_string(amount) +
		") "
		"ON CONFLICT DO NOTHING;"
	);
	tx.commit();
}