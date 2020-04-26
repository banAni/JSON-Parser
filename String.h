#pragma once
#include<iostream>
#include "Value.h"
using namespace std;
class String :public Value {
private:
	string value;
public:
	String(const string _value);
	void print();
	void search(string&);
	void printValue();
};
String::String(const string _value) :value(_value) {};
void String::print()
{
	cout << '"' << value << '"';
}
void String::printValue() {
	cout << value;
}
void String::search(string& key) {
	printValue();
}