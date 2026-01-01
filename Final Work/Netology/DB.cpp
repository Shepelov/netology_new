#include "DB.h"

DB::DB(std::string host, std::string port, std::string dbname, std::string user, std::string password, bool erase) {
	conn = new pqxx::connection(
		"host=" + host + " " +
		"port=" + port + " " +
		"dbname=" + dbname + " " +
		"user=" + user + " "
		"password=" + password);
	if (erase) {	//если установлен флаг выполняем удаление таблицы с данными перед началом работы паука
		pqxx::work tx{ *conn };
		tx.exec(
			"DROP TABLE IF EXISTS _spider_urls, _spider_words, _spider_crosstable"
		);
		tx.commit();
	}
	//создание таблиц для паука
	pqxx::work tx{*conn};
	tx.exec(
		"CREATE TABLE IF NOT EXISTS _spider_urls("
		"id SERIAL PRIMARY KEY, "
		"url TEXT NOT NULL UNIQUE"
		");"
	);

	tx.exec(
		"CREATE TABLE IF NOT EXISTS _spider_words("
		"id SERIAL PRIMARY KEY, "
		"word TEXT NOT NULL UNIQUE"
		");"
	);

	tx.exec(
		"CREATE TABLE IF NOT EXISTS _spider_crosstable("
		"id_url INTEGER REFERENCES _spider_urls(id), "
		"id_word INTEGER REFERENCES _spider_words(id), "
		"quantity INTEGER NOT NULL, "
		"UNIQUE (id_url, id_word)"
		");"
	);
	tx.commit();
}

DB::~DB() {
	delete conn;
}

void DB::addEntry(std::string url, std::string word, int amount) {
	try {				//на всякий случай экранируем попытку записи в БД от возможных ошибок
		pqxx::work tx{ *conn };

		if (!isUrlExists(url, &tx)) {	//вносим url в БД если его там еще нет
			tx.exec(
				"INSERT INTO _spider_urls(url) "
				"VALUES('" + url + "')"
			);
		}

		if (!isWordExists(word, &tx)) {	//вносим слово в БД если его там еще нет
			tx.exec(
				"INSERT INTO _spider_words(word) "
				"VALUES('" + word + "')"
			);
		}

		tx.exec("INSERT INTO _spider_crosstable (id_url, id_word, quantity) VALUES ("
			"(SELECT id FROM _spider_urls WHERE url = '" + url + "'),"
			"(SELECT id FROM _spider_words WHERE word = '" + word + "'), '" + std::to_string(amount) + "')"
			);
		tx.commit();
	}
	catch (std::exception e) {
		return;		//если запись в БД по какой-то причине не удалась 
					//делаем возврат к вызывающей функции для следующей итерации записи
	}
	
}

std::map<std::string, int> DB::getUrl(const std::string& keyword) {
	std::map<std::string, int> result;
	
	pqxx::work tx{ *conn };

	std::string key_esc = tx.esc(keyword);

	for (auto [url, amount] : tx.query<std::string, int>
		("SELECT _spider_urls.url, _spider_crosstable.quantity "
			"FROM _spider_urls "
			"JOIN _spider_crosstable ON _spider_urls.id = _spider_crosstable.id_url "
			"JOIN _spider_words ON _spider_crosstable.id_word = _spider_words.id "
			"WHERE _spider_words.word = '" + key_esc + "' "))
	{
		result[url] = amount;
	};
	return result;
}

bool DB::isUrlExists(std::string url) {	//проверяет наличие заданного url в БД, чтобы не парсить его повторно
	try {
		std::map<std::string, int> result;
		pqxx::work tx{ *conn };

		return tx.query_value<bool>("SELECT EXISTS(SELECT id FROM _spider_urls WHERE url = '" + url + "');");
	}
	catch (std::exception e) {
		return true;
	}
	
}bool DB::isUrlExists(std::string url, pqxx::work* tx) {	//перегрузка для внутреннего использования - 
	try {													//без создания дополнительной транзакции
		return tx->query_value<bool>("SELECT EXISTS(SELECT id FROM _spider_urls WHERE url = '" + url + "');");
	}
	catch (std::exception e) {
		return true;
	}

}

bool DB::isWordExists(std::string word, pqxx::work* tx) {	//проверяет наличие заданного слова в БД
	try {
		return tx->query_value<bool>("SELECT EXISTS(SELECT id FROM _spider_words WHERE word = '" + word + "');");
	}
	catch (std::exception e) {
		return true;
	}

}