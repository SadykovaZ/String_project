#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class string_
{
	char*str;
	int length;
public:
	string_();
	string_(int length);
	string_(const char*str);
	string_(const string_&obj);
	string_&operator=(const string_&obj);
	void print();
	//ввод строки с клавиатуры
	void input();
	void insert(int position, const char *str);
	int getLength();
	const char* getString();
	void setString(const char*str);
	~string_();
	void clear();
};

ostream& operator<<(ostream&os, string_&s);
istream& operator>>(istream&is, string_&s);

#endif

