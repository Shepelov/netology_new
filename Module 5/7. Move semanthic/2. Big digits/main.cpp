#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class big_integer {
public:
    big_integer(const std::string integer) {    //число записываем в обратном порядке разрядов.
        this->integer = integer;                //Так проще будет выполнять с ним математические операции
        std::reverse(this->integer.begin(), this->integer.end());
    }

    big_integer(big_integer& other) {
        this->integer = other.integer;
    }

    big_integer(big_integer&& other) noexcept {
        this->integer = std::move(other.integer);
    }

    //деструктор тут не нужен, т.к. std::string самостоятельно контролирует память

    friend std::ostream& operator << (std::ostream& out, const big_integer in) {
        std::string visualisation = in.integer;
        std::reverse(visualisation.begin(), visualisation.end());
        return out << visualisation;
    }

    big_integer& operator = (const big_integer& other) {
        this->integer = other.integer;

        return *this;
    }

    big_integer& operator = (big_integer&& other) noexcept {
        this->integer = std::move(other.integer);

        return *this;
    }

    big_integer operator + (big_integer& other) {
        std::string res_str;
        int next_pos = 0; //хранит десятки при сложении
        int max_digits = integer.size() > other.integer.size() ? integer.size() : other.integer.size();
        for (int i = 0; i < max_digits; ++i) {
            int summ = get_int(i) + other.get_int(i) + next_pos;
            next_pos = summ / 10;
            int curr_pos = summ - next_pos * 10;
            res_str.append(std::to_string(curr_pos));
        }
        if (next_pos != 0) {
            res_str.append(std::to_string(next_pos));
        }
        std::reverse(res_str.begin(), res_str.end());
        big_integer result(res_str);        //здесь можно было бы сделать перемещение result в integer и вернуть *this, но тогда
        //значением number1 в дальнейшем невозможно будет пользоваться
        return result;
    }

    big_integer operator + (int other) {    //перегрузка оператора + для целого числа
        big_integer other_big(std::to_string(other));
        big_integer result = *this + other_big;

        return result;
    }

    big_integer operator * (big_integer& other) {
        big_integer summ("0");    //хранит сумму последовательных умножений
        for (int i = 0; i < other.integer.size(); ++i) {
            std::string temp;   //временная строка для текущего умножения
            int next_pos = 0; //хранит десятки при умножении
            for (int p = 0; p < i; ++p) {
                temp.append(std::to_string(0));
            }
            for (int j = 0; j < integer.size(); ++j) {
                int summ = get_int(j) * other.get_int(i) + next_pos;
                next_pos = summ / 10;
                int curr_pos = summ - next_pos * 10;
                temp.append(std::to_string(curr_pos));
            }
            if (next_pos != 0) {
                temp.append(std::to_string(next_pos));
            }
            std::reverse(temp.begin(), temp.end());
            big_integer curr_res(temp);
            summ = summ + curr_res;
        }
        return summ;
    }

    big_integer operator * (int other) {    //перегрузка оператора * для целого числа
        big_integer other_big(std::to_string(other));
        big_integer result = *this * other_big;

        return result;
    }
private:
    std::string integer;

    int get_int(int index) {            //вспомогательная функция: возвращает int по индексу в строке
        if (index < integer.size()) {   //(нумерация с младшего разряда)
            return integer[index] - 48;
        }
        else {
            return 0;
        }
    }
};

//test
int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result << std::endl; // 193 099

    auto result2 = number1 * number2;
    std::cout << result2 << std::endl; // 8 996 887 300

    auto result3 = number1 + 300;
    std::cout << result3 << std::endl; // 114 875

    auto result4 = number1 * 35;
    std::cout << result4 << std::endl; // 4 010 125

    return 0;
}