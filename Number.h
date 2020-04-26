#pragma once
#include<iostream>
#include "Value.h"
using namespace std;
//to separate h from cpp
class Number:public Value {
private:
	double number;
public:
	Number(double number) { this->number = number; }
	void search(string&);
	void print();
	void printValue();

};
void Number::print() {
	cout << number << ',';
}
void Number::printValue() {
	cout << number;
}
void Number::search(string& key) {
	printValue();
}