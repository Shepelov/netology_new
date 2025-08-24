#include <iostream>
#include <map>
#include <fstream>
#include <string>

class ini_parser {
public:
    ini_parser(std::string filename) {
        std::ifstream file{ filename };
        if (!file.is_open()) {
            throw std::runtime_error("INI file open failure!");
        }
        else {
            std::string data; //std::string для построчного считывания из файла
            std::string section_name; //имя секции
            int ini_line{ 1 }; //счетчик строк
            while (std::getline(file, data)) {
                data = data.substr(0, data.find(";"));  //удаляем комментарии
                if (data.size() == 0) {}        //проверка на пустую строку для исключения ее из дальнейшей обработки
                else if (data[0] == '[') {                   //проверка строки на имя секции
                    if (data.find(']') > data.length()) {   //проверяем корректность объявления секции
                        throw std::runtime_error("Incorrect section initialisation on line " + ini_line);
                    }
                    else {
                        int end_pos = data.find(']');
                        section_name = data.substr(1, end_pos - 1);//если ОК - меняем section_name
                    }
                }
                else if (data.find('=') < data.length()) {          //проверка строки на объявление переменной
                    int pos = data.find('=');
                    std::string var_name = delete_spaces(data.substr(0, pos), ini_line);
                    var_name = section_name + "." + var_name;
                    std::string var_value = delete_spaces(data.substr(pos + 1), ini_line);
                    if (values.find(var_name) == values.end()) {        //если такого ключа в мапе нет - создаем
                        values.insert(std::pair<std::string, std::string>(var_name, var_value));
                    }
                    else {                                              //если есть - меняем значение
                        values[var_name] = var_value;
                    }
                }
                ++ini_line;
            }
        }
        
    }

    template <typename T>
    T get_value(std::string key) {
        if (values.find(key) == values.end()) {
            throw std::runtime_error(not_found_message(key));
        }
        else {
            return static_cast<T>(values[key]);
        }
    }

    template <>
    int get_value(std::string key) {
        if (values.find(key) == values.end()) {
            throw std::runtime_error(not_found_message(key));
        }
        else {
            return std::stoi(values[key]);
        }
    }

    template <>
    double get_value(std::string key) {
        if (values.find(key) == values.end()) {
            throw std::runtime_error(not_found_message(key));
        }
        else {
            return std::stod(values[key]);
        }
    }
private:
    std::map<std::string, std::string> values;
    std::string delete_spaces(std::string in, int ini_line) {       //вспомогательная функция - удаление пробелов
        if (in.length() == 0) {                                 //если слева или справа от знака равенства пустота выбрасываем исключение
            throw std::runtime_error("Synthax error on line " + std::to_string(ini_line) + "!");
        }
        while (in[0] == ' ') {
            in.erase(0, 1);
        }
        while (in[in.length() - 1] == ' ') {
            in.erase(in.length() - 1);
        }
        return in;
    }

    std::string not_found_message(std::string key) {    //вспомогательная функция - формирует сообщение для исключения
        std::string section_name = key.substr(0, key.find('.'));
        std::string var_name = key.substr(key.find('.') + 1);
        std::string message = "Variable \"" + var_name + "\" does not found in section \"" + section_name + "\"";

        return message;
    }
};

int main()
{
    try {
        ini_parser parser("settings.ini");
        auto value = parser.get_value<double>("Section1.var1");
        std::cout << value;
    }
    catch(const std::runtime_error& e){
        std::cerr << e.what();
    }
    
    return 0;
}