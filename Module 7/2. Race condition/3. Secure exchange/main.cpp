#include <mutex>
#include <iostream>

class Data {
public:
    std::mutex mtx;
    int value;

    Data(int value) : value{ value } {};
};

void swap(Data& d1, Data& d2) { //вариант с lock-unlock
    d1.mtx.lock();
    d2.mtx.lock();

    int temp = d1.value;
    d1.value = d2.value;
    d2.value = temp;

    d1.mtx.unlock();
    d2.mtx.unlock();
}
/*
void swap(Data& d1, Data& d2) { //вариант с scoped_lock
    std::scoped_lock sl(d1.mtx, d2.mtx);

    int temp = d1.value;
    d1.value = d2.value;
    d2.value = temp;
}

void swap(Data& d1, Data& d2) { //вариант с unique_lock
    std::unique_lock<std::mutex> ul1(d1.mtx);
    std::unique_lock<std::mutex> ul2(d2.mtx);

    int temp = d1.value;
    d1.value = d2.value;
    d2.value = temp;
}
*/
int main(){
    
    Data d1 = Data(10);
    Data d2 = Data(20);

    swap(d1, d2);

    std::cout << "d1.value = " << d1.value << ", d2.value = " << d2.value << std::endl;

    return 0;
}