#include <thread>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <chrono>

struct thread_info {
    int progress = 0;
    double elapsed_time = 0;
};

void refresh_screen(std::vector<std::thread>& threads, std::vector<thread_info>& t_info, std::vector<int>& calc) {
    do {
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); //интервал обновления экрана
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        std::cout << "N\tID\tProgress\t\t%\tElapsed Time" << std::endl;

        for (int i = 0; i < threads.size(); ++i) {
            int percent = t_info[i].progress * 100 / calc[i];
            int elem = percent / 5;
            std::cout << i+1 << "\t" << threads[i].get_id() << "\t";
            for (int i = 0; i <= elem; ++i) {
                std::cout << "*";
            }
            for (int i = 0; i < 20 - elem; ++i) {
                std::cout << "-";
            }
            std::cout << "\t" << percent;
            if (t_info[i].elapsed_time > 0) {
                std::cout << "\t" << t_info[i].elapsed_time;
            }
            std::cout << std::endl;
        }

        
        
    } while (true);
}

void calculate(int amount_of_calc, thread_info& t_info) {
    auto time_start = std::chrono::steady_clock::now();
    for (int i = 0; i < amount_of_calc; ++i) {
        t_info.progress++;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    auto time_end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_elapsed = time_end - time_start;
    t_info.elapsed_time = time_elapsed.count();
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); //приостанавливаем поток, чтоб успел обновиться экран.
    //без этого не прописывается значение времени работы последнего потока
}

int main(){
    
    int amount_of_threads = 6;  //количество потоков
    std::vector<int> amount_of_calc = { 200, 300, 150, 180, 250, 400 };   //длины расчетов для каждого потока

    std::vector<std::thread> ts; //хранит потоки
    std::vector<thread_info> t_info; //хранит информацию для каждого потока
    for (int i = 0; i < amount_of_threads; ++i) {
        t_info.push_back(thread_info{});
    }

    std::thread refresh(refresh_screen, std::ref(ts), std::ref(t_info), std::ref(amount_of_calc)); //запуск потока для обновления экрана
    refresh.detach();


    for (int i = 0; i < amount_of_threads; ++i) {
        ts.push_back (std::thread (calculate, amount_of_calc[i], std::ref(t_info[i])));
    }

    for (int i = 0; i < amount_of_threads; ++i) {
        ts[i].join();
    }

    return 0;
}