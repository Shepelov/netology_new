#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <future>

std::vector<int> create_random_vector(int size, int max) { //генерация рандомного списка
    std::vector<int> list;
    for (int i = 0; i < size; ++i){
        list.push_back(rand() % max + 1);
    }
    return list;
}

void print_list(std::vector<int> list) {
    for (int value : list) {
        std::cout << value << " ";

    }
    std::cout << std::endl;
}

void min_in_list(std::vector<int>& list, int position, std::promise<int> promise) {
    if (list.size() - position == 1) {
        promise.set_value(position);
    }
    else {
        int min = list[position];
        int min_position = position;
        for (int i = position + 1; i < list.size(); ++i) {
            if (list[i] < min) {
                min = list[i];
                min_position = i;
            }
        }
        promise.set_value(min_position);
    }
}

void sort_list(std::vector<int>& list) {
    for (int i = 0; i < list.size(); ++i) {
        std::promise<int> promise;
        std::future<int> future = promise.get_future();
        auto find_min = std::async(min_in_list, std::ref(list), i, std::move(promise));
        int swap_index = future.get();
        int temp = list[i];
        list[i] = list[swap_index];
        list[swap_index] = temp;
    }
}

int main(){
    
    //входные данные
    srand(time(0)); //определение зерна генерации для рандома
    int size = 20; //размер исходного списка для сортировки
    int max = 999; //максимальное значение для списка
    
    std::vector<int> list = create_random_vector(size, max);
    std::cout << "Vector before sorting:" << std::endl;
    print_list(list);
    sort_list(list);
    std::cout << "Vector after sorting:" << std::endl;
    print_list(list);

    return 0;
}