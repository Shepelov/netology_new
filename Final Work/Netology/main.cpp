#define _CRT_SECURE_NO_WARNINGS

#include <memory>

#include "iniParser.h"
#include "spyder.h"
#include "DB.h"
#include "Server.h"



int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

	iniParser* ini;
	DB* database;

	try {
		ini = new iniParser ("settings.ini");
	}
	catch (std::runtime_error e) {
		std::cout << "INI file failure!" << std::endl;
		exit(1);
	}
	
	try {
		database = new DB (
							ini->get_value<std::string>("DB.host"),
							ini->get_value<std::string>("DB.port"),
							ini->get_value<std::string>("DB.dbname"),
							ini->get_value<std::string>("DB.user"),
							ini->get_value<std::string>("DB.password"),
							ini->get_value<bool>("DB.erase")
						);
	}
	catch (std::exception e) {
		std::cout << "DB open failure!" << std::endl;
		exit(2);
	}
	
	if (ini->get_value<std::string>("RunMode.mode") == "SPIDER_ONLY" || ini->get_value<std::string>("RunMode.mode") == "ALL") {
		Spyder spyder(ini->get_value<std::string>("Spider.start"), ini->get_value<int>("Spider.depth"), database);
	}
	
	if (ini->get_value<std::string>("RunMode.mode") == "SERVER_ONLY" || ini->get_value<std::string>("RunMode.mode") == "ALL") {
		Server server(ini->get_value<std::string>("Server.ip"), ini->get_value<std::string>("Server.port"), *database);
	}
}