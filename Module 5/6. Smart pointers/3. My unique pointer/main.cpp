#include <iostream>

template <typename T>
class my_unique_ptr {
private:
    T* ptr = nullptr;
    T& operator= (const T& other) = delete; //запрещаем использование оператора =
    my_unique_ptr(const my_unique_ptr&) {}  //запрещаем использование конструктор копирования
public:
    my_unique_ptr(T* raw_ptr) : ptr{ raw_ptr } {}

    ~my_unique_ptr() {
        if (ptr) {
            delete ptr;
        }
    }

    T operator* () {
        if (ptr) {
            return *ptr;
        }
    }

    T* operator-> () {
        if (ptr) {
            return ptr;
        }
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
    
    //std::string str = "Hello world!"
    my_unique_ptr<std::string> my_ptr2(new std::string("Hello wolrd!"));
    std::cout << my_ptr2->size() << std::endl;

    return 0;
}