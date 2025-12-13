#include "spyder.h"

Spyder::Spyder(std::string startPage, int depth) {
    const int cores = std::thread::hardware_concurrency() - 1;
    URL startUrl = { startPage, 1 };
    ThreadPool pool(cores, depth);
    std::thread t1(&ThreadPool::submit, &pool, startUrl);
    t1.join();
}

Spyder::~Spyder() {

}