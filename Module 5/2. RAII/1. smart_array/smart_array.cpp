#include "smart_array.h"
#include <iostream>

smart_array::smart_array(int amount_elements) {
	pArray = new int[amount_elements];
	fact_size = amount_elements;
	logic_size = 0;
};

void smart_array::add_element(int value) {
	if (fact_size - logic_size < 1) { //��������� ������� ���������� ���������� ��������� �������
		int* temp = new int[fact_size * 2]; //�������� ������ ������� � �������� �2 �� �����������
		fact_size *= 2;
		for (int i = 0; i < logic_size; ++i) {
			temp[i] = pArray[i];
		}
		delete[] pArray;
		pArray = temp;
	}
	pArray[logic_size] = value;
	logic_size++;
};

int smart_array::get_element(int number) {
	if (number <= 0 || number > logic_size) {
		return 0; //���� ���������� �������� ������� �� ������� ����������� ������� ������� ������ "0"
	}
	return pArray[number - 1];
};

smart_array::~smart_array() {
	delete[] pArray;
};