#include "Safe_queue.h"
#include "Thread_pool.h"


void foo1() {
    std::cout << "Function: " << __FUNCTION__ << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void foo2() {
    std::cout << "Function: " << __FUNCTION__ << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}


int main(int argc, char** argv) {
    const int cores = std::thread::hardware_concurrency() - 1;
    std::vector<std::function<void()>> func_vector{ foo1, foo2 };
    int amount_of_submits = 8;
    Thread_pool pool(cores);
    std::thread t1(&Thread_pool::submit, &pool, func_vector, amount_of_submits);
    t1.join();

    return 0;
}