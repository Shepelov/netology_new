#include "spyder.h"

Spyder::Spyder(std::string startPage, int depth, DB* database) {
    const int cores = std::thread::hardware_concurrency() - 1;
    startPage = startPage + "/";
    URL startUrl = { startPage, 1 };
    ThreadPool pool(cores, depth, startUrl, database);
}

Spyder::~Spyder() {

}