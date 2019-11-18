#pragma once
#include <iostream>
class MyString {
	char* arr;
	int len;
	int memory_capacity;

public:
	 MyString(int capacity);
	explicit MyString(char c);
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
	int find(int from, MyString& str) const;
	int find(int from, const char* str) const;
	int find(int from, char c) const;
	int compare(MyString& str) const;
	int compare(const char* str) const;
	int compare(char c) const;
};