#include <thread>
#include <chrono>
#include <iostream>
#include <atomic>

void clients(std::atomic<int>& counter, int max_clients) {
    for (int i = 0; i < max_clients; ++i) {
        ++counter;
        int value = counter.load();
        std::cout << "In queue: " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void operationist(std::atomic<int>& counter) {
    do {
        --counter;
        int value = counter.load();
        std::cout << "In queue: " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    } while (counter > 0);
}

int main()
{
    std::atomic<int> clients_counter = 0;

    std::thread t1(clients, std::ref(clients_counter), 10);
    std::thread t2(operationist, std::ref(clients_counter));

    t1.join();
    t2.join();

    return 0;
}