#include "MyString.h"
MyString::MyString(int capacity)
{
	arr = new char[capacity];
	len = 0;
	memory_capacity = capacity;
}
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

MyString& MyString::erase(int loc, int num)
{
	if (num <0 ||loc < 0 || loc >= len)
		return *this;
	for (int i = loc + num; i < len; i++)
		arr[i - num] = arr[i];

	len = len - num;
	return *this;
}
int MyString::find(int from, MyString& str) const
{
	int i, j;
	if (str.len == 0)	return -1;
	for (i = from; i < len - str.len; i++)
	{
		for (j = 0; j < str.len; j++)
		{
			if (arr[i + j] != str.arr[j]) break;
		}
		if (j == str.len)	return i;
	}
	return -1;
}
int MyString::find(int from, const char* str) const
{
	MyString temp(str);
	return find(from, temp);
}
int MyString::find(int from, char c) const
{
	MyString temp(c);
	return find(from, temp);
}
int MyString::compare(MyString& str) const
{
	for (int i = 0; i < std::fmin(len, str.len); i++)
	{
		if(arr[i] > str.arr[i])
			return 1;
		else if(arr[i] < str.arr[i])
			return -1;
	}

	if (len == str.len)
		return 0;
	else if (len > str.len)
		return 1;
	else
		return -1;
}
int MyString::compare(const char* str) const
{
	MyString temp(str);
	return compare(temp);
}
int MyString::compare(char c) const
{
	MyString temp(c);
	return compare(temp);
}
