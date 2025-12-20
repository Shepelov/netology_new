#include "spyder.h"
#include "DB.h"

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

	DB Database(false);
	Spyder spyder("gismeteo.ru/", 2, Database);


}