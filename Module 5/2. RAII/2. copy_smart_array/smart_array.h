#pragma once
class smart_array
{
public:
	smart_array(int amount_elements);
	void add_element(int value);
	int get_element(int number);
	~smart_array();
	smart_array& operator = (const smart_array& operand);
private:
	int* pArray;
	int logic_size;
	int fact_size;
};

