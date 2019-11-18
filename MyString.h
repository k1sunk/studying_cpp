#pragma once
#include <iostream>
class MyString {
	char* arr;
	int len;
	int memory_capacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();
	int length() const;
	void print() const;
	void println() const;
	static int strlen(const char* str);
	MyString& assign(const char* str);
	MyString& assign(const MyString& str);
	int capacity() const;
	void reserve(int size);
	char at(int index) const;
	MyString& insert(int loc, char c);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, const MyString& str);
	MyString& erase(int loc, int num);
};