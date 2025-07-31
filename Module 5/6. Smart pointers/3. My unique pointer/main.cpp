#include <iostream>

template <typename T>
class my_unique_ptr {
private:
    T* ptr = nullptr;
    T& operator= (const T& other) = delete; //запрещаем использование оператора =
    my_unique_ptr(const my_unique_ptr&) {}  //запрещаем использование конструктор копирования
public:
    my_unique_ptr(T* raw_ptr) : ptr{raw_ptr} {}

    ~my_unique_ptr() {
        if (ptr) {
            delete ptr;
        }
    }

    T operator* () {
        return *ptr;
    }

    T* release() {
        T* old_ptr = ptr;
        ptr = nullptr;
        return old_ptr;
    }
};

int main()
{
    //проверка функционала
    my_unique_ptr<int> my_ptr(new int(10));
    std::cout << *my_ptr << std::endl;
    int* ptr = my_ptr.release();

    return 0;
}