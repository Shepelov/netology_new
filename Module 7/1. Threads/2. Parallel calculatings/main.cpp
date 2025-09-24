#include <thread>
#include <chrono>
#include <iostream>
#include <vector>

std::vector<int> make_rand_vector(int vector_size){
    std::vector<int> vec;
    for (int i = 0; i < vector_size; ++i) {
        vec.push_back(rand() % 100000);
    }
    return vec;
}

void hardware_print() {
    std::cout << "Hardware cores - " << std::thread::hardware_concurrency() << "\n\n";
    std::cout << "\t\t1 000\t\t10 000\t\t100 000\t\t1 000 000\n\n";
}

std::once_flag hardware;

std::vector<int> summ_vector(std::vector<int>& first, std::vector<int>& second, int threads_amount, int current_thread) {
    std::vector<int> vec;
    std::call_once(hardware, hardware_print);

    int start = first.size() / threads_amount * (current_thread - 1);
    int end = first.size() / threads_amount * current_thread;

    for (int i = start; i < end; ++i) {
        vec.push_back(first[i] + second[i]);
    }
    
    

    return vec;
}

int main()
{
    for (int i = 1; i <= 16; i *= 2) {
        for (int j = 1000; j <= 1000000; j *= 10) {
            auto vec1 = make_rand_vector(j);
            auto vec2 = make_rand_vector(j);
            std::vector<std::thread> threads;
            auto time_start = std::chrono::steady_clock::now();
            for (int m = 1; m <= i; ++m) {
                threads.push_back(std::thread(summ_vector, std::ref(vec1), std::ref(vec2), i, m));
            }
            for (auto& t : threads)
            {
                t.join();
            }
            auto time_end = std::chrono::steady_clock::now();
            std::chrono::duration<double> time_elapsed = time_end - time_start;
            if (j == 1000) {
                std::cout << i << " thread(s)\t";
            }
            std::cout << time_elapsed.count() << "s\t";
        }
        std::cout << "\n";
    }


    
    return 0;
}