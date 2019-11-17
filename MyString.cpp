#include "MyString.h"
MyString::MyString(char c)
{
	arr = new char[1];
	len = 1;
	arr[0] = c;
	memory_capacity = 1;
}
MyString::MyString(const char* str)
{
	len = strlen(str);
	arr = new char[len];

	for (int i = 0; i != len; i++)
	{
		arr[i] = str[i];
	}
	memory_capacity = len;
}
MyString::MyString(const MyString& str)
{
	len = str.len;
	arr = new char[len];
	for (int i = 0; i != len; i++) arr[i] = str.arr[i];
	memory_capacity = len;
}
MyString::~MyString() { delete[] arr; }

int MyString::length() const { return len; }

void MyString::print() const {
	for (int i = 0; i != len; i++)
		std::cout << arr[i];
}
void MyString::println() const {
	print();
	std::cout << std::endl;
}
int MyString::strlen(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

MyString& MyString::assign(const char* str) {
	int new_len = strlen(str);
	if (new_len > memory_capacity)
	{
		delete[] arr;
		arr = new char[new_len];
		memory_capacity = new_len;
	}
	len = strlen(str);
	for (int i = 0; i != len; i++)
		arr[i] = str[i];
	return *this;
}
MyString& MyString::assign(const MyString& str) {
	if (str.len > len)
	{
		delete[] arr;
		arr = new char[str.len];
		memory_capacity = str.len;
	}
	len = str.len;
	for (int i = 0; i != len; i++)
		arr[i] = str.arr[i];
	return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size)
{
	if (size > memory_capacity)
	{
		char* prev_arr = arr;
		arr = new char[size];
		
		memory_capacity = size;
		for (int i = 0; i != len; i++)	arr[i] = prev_arr[i];
		
		delete[] prev_arr;
	}
	// reloc

}
char MyString::at(int index) const {
	if (index < 0 || index >= len)
		return NULL;
	else
		return arr[index];
}
// re-using the function through Object's constructor
MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, const MyString& str) {

	int insert_len = str.len;
	if (loc >= len || loc < 0)
		return *this;

	if (len + insert_len > memory_capacity)
	{
		memory_capacity = len + insert_len;

		char* prev_arr = arr;
		arr = new char[len + insert_len];
		for (int i = 0; i != loc; i++) arr[i] = prev_arr[i];
		for (int i = 0; i != insert_len; i++) arr[i + loc] = str.arr[i];
		for (int i = loc; i != len; i++) arr[i + insert_len] = prev_arr[i];

		len = len + str.len;

		return *this;
	}

	for (int i = len - 1; i != loc - 1; i--) arr[i + insert_len] = arr[i];
	for (int i = 0; i != insert_len; i++) arr[i + loc] = str.arr[i];

	len = len + str.len;

	return *this;
}

