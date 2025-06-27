#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

class Address{
private:
	std::string city;
	std::string street;
	int houseNumber;
	int flatNumber;
public:
	Address (): city("N/A"), street("N/A"), houseNumber(0), flatNumber(0) {}
	Address(std::string city, std::string street, int houseNumber, int flatNumber): city(city), street(street), houseNumber(houseNumber), flatNumber(flatNumber){}
	std::string getAddress(){
		return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(flatNumber);
	}
	std::string getCity(){
		return city;
	}
};

void sortAddress (Address* addresses, int size){
	bool swap;
	do{
		swap = false;
		for (int i = 1; i < size; ++i){
			if (addresses[i-1].getCity() > addresses[i].getCity()){
				Address temp = addresses[i];
				addresses[i] = addresses[i-1];
				addresses[i-1] = temp;
				swap = true;
			}
		}
	}
	while (swap);
}

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	std::string amount;
	Address* addresses;

	std::ifstream input ("input.txt"); 
	if (!input.is_open()){
		std::cout << "Ошибка открытия файла с входными данными!" << std::endl;
	}
	else{
		getline(input, amount);

		addresses = new Address [std::stoi(amount)];

		for (int i = 0; i < std::stoi(amount); ++i){
			std::string city;
			std::string street;
			std::string houseNumber;
			std::string flatNumber;
			getline(input, city);
			getline(input, street);
			getline(input, houseNumber);
			getline(input, flatNumber);
			addresses[i] = Address (city, street, std::stoi(houseNumber), std::stoi(flatNumber));
		}
		input.close();

		sortAddress(addresses, std::stoi(amount));

		std::ofstream output ("output.txt");
		if (!output.is_open()){
			std::cout << "Ошибка открытия файла для выходных данных!" << std::endl;
		}
		else{
			output << std::stoi(amount) << "\n";
			for (int i = 0; i < std::stoi(amount); ++i){
				output << addresses[i].getAddress() << "\n";	
			}
			output.close();
		}  

		delete[] addresses;
		std::cout << "Программа окончила свою работу!" << std::endl;
	}
	return 0;
}