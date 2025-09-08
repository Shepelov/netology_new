#include <iostream>
#include <clocale>
#include <Windows.h>
#include <pqxx/pqxx>

class DB_manager {
public:
	//создание БД
	void create_db(pqxx::connection &c) {
		pqxx::work tx{ c };
		tx.exec(
			"CREATE TABLE IF NOT EXISTS clients("
			"id SERIAL PRIMARY KEY, "
			"first_name VARCHAR(40) NOT NULL, "
			"second_name VARCHAR(40) NOT NULL, "
			"email VARCHAR(60) NOT NULL, "
			"UNIQUE(first_name, second_name)"
			");"
		
			"CREATE TABLE IF NOT EXISTS phones("
			"id INTEGER REFERENCES clients(id), "
			"phone INTEGER NOT NULL, "
			"UNIQUE(id, phone)"
			");"
		);
		tx.commit();
	}

	//добавление нового клиента
	void add_client(pqxx::connection& c, std::string first_name, std::string second_name, std::string email) {
		pqxx::work tx{ c };
		tx.exec("INSERT INTO clients(first_name, second_name, email) "
			"VALUES('" + first_name + "', '" + second_name + "', '" + email + "')");
		tx.commit();
	}

	//добавление телефона для существующего клиента
	void add_phone(pqxx::connection& c, std::string first_name, std::string second_name, int phone) {
		pqxx::work tx{ c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' "
			"AND second_name = '" + second_name + "'");
		tx.exec("INSERT INTO phones(id, phone) "
			"VALUES(" + std::to_string(id) + ", " + std::to_string(phone) + ")");
		tx.commit();
	}

	//изменение данных существующего клиента
	void change_client(pqxx::connection& c, std::string first_name, std::string second_name, std::string new_first_name, 
						std::string new_second_name, std::string new_email) {
		pqxx::work tx{ c };
		tx.exec("UPDATE clients SET first_name = '" + new_first_name + "', second_name = '" + new_second_name + "',"
			"email = '" + new_email + "' WHERE first_name = '" + first_name + "' AND second_name = '" + second_name + "'");
		tx.commit();
	}

	//удаление телефона у существующего клиента
	void delete_phone(pqxx::connection& c, std::string first_name, std::string second_name, int phone) {
		pqxx::work tx{ c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' "
			"AND second_name = '" + second_name + "'");
		tx.exec("DELETE FROM phones WHERE id = " + std::to_string(id) + " AND phone = " + std::to_string(phone));
		tx.commit();
	}

	//удаление существующего клиента
	void delete_client(pqxx::connection& c, std::string first_name, std::string second_name) {
		pqxx::work tx{ c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' "
			"AND second_name = '" + second_name + "'");
		//сначала удаляем все телефоны клиента во избежание конфликта
		tx.exec("DELETE FROM phones WHERE id = " + std::to_string(id));
		//затем - самого клиента из БД
		tx.exec("DELETE FROM clients WHERE first_name = '" + first_name + "' AND second_name = '" + second_name + "'");
		tx.commit();
	}

	//поиск клиента по его данным
	void find_client(pqxx::connection& c, std::string search_field, std::string search_request) {
		std::string db_request;
		if (search_field == "first_name") {
			db_request = "SELECT id, first_name, second_name, email FROM clients WHERE first_name = '" + search_request +"'";
		}
		else if (search_field == "second_name") {
			db_request = "SELECT id, first_name, second_name, email FROM clients WHERE second_name = '" + search_request + "'";
		}
		else if (search_field == "email") {
			db_request = "SELECT id, first_name, second_name, email FROM clients WHERE email = '" + search_request + "'";
		}
		else {
			throw std::exception("Invalid search field type!");
		}

		pqxx::work tx{ c };
		for (auto [id, first_name, second_name, email] : tx.query<int, std::string, std::string, std::string>(
			db_request))
		{
			std::cout << id << ". " << first_name << " " << second_name << " " << email << "\n";
		}
	}

	//перегрузка функции для поиска по телефону
	void find_client(pqxx::connection& c, std::string search_field, int phone) {
		if (search_field == "phone") {
			pqxx::work tx{ c };
			int id = tx.query_value<int>("SELECT id FROM phones WHERE phone = " + std::to_string(phone));
			for (auto [id, first_name, second_name, email] : tx.query<int, std::string, std::string, std::string>(
				"SELECT id, first_name, second_name, email FROM clients WHERE id = " + std::to_string(id)))
			{
				std::cout << id << ". " << first_name << " " << second_name << " " << email << "\n";
			}
		}
		else {
			throw std::exception("Invalid search field type!");
		}
		
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);


	try {
		pqxx::connection conn(
			"host=localhost "
			"port=5432 "
			"dbname=postgres "
			"user=postgres "
			"password=1989 ");
		DB_manager* db = new DB_manager();
		//примеры запросов к БД для демонстрации функционала:

		db->create_db(conn);
		db->add_client(conn, "Joe", "Biden", "joe.biden@task.com");
		db->add_client(conn, "Donald", "Trump", "trump@trump.com");
		db->add_client(conn, "Barak", "Obama", "obama@whitehouse.com");
		db->add_phone(conn, "Joe", "Biden", 55555);
		db->add_phone(conn, "Barak", "Obama", 77777);
		db->add_phone(conn, "Joe", "Biden", 22222);
		db->change_client(conn, "Joe", "Biden", "Joe", "Biden", "biden@whitehouse.com");
		db->delete_phone(conn, "Joe", "Biden", 55555);
		db->delete_client(conn, "Barak", "Obama");
		db->find_client(conn, "first_name", "Joe");
		db->find_client(conn, "second_name", "Trump");
		db->find_client(conn, "email", "biden@whitehouse.com");
		db->find_client(conn, "phone", 22222);

		}

	catch (pqxx::sql_error e)
	{
		std::cout << e.what() << std::endl;
	}

	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
