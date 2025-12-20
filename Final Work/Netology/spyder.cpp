#include "spyder.h"

Spyder::Spyder(std::string startPage, int depth, DB Database) {
    const int cores = std::thread::hardware_concurrency() - 1;
    URL startUrl = { startPage, 1 };
    ThreadPool pool(cores, depth, startUrl, Database);
}

Spyder::~Spyder() {

}