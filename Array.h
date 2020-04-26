#pragma once
#include<iostream>
#include<vector>
#include "Value.h"
using namespace std;
class Array :public Value {
private:
	vector<Value*> value;
public:
	Array(vector<Value*> _value);
	void print();
	void search();
	void printValue();
};
Array::Array(vector<Value*> _value) : value(_value) {};
void Array::printValue() {
	cout << '[';
	cout << " ";
	for (int i = 0;i <= value.size();i++) {
		value[i]->printValue();
		if (i != value.size()) {
			cout << "," << " ";
		}
	}
	cout << ']';
}
void Array::print()
{
	cout << '['<<endl;
	cout << " ";
	for (int i = 0;i <= value.size();i++) {
		value[i]->printValue();
		if (i != value.size()) {
			cout << "," << " "<<endl;
		}
	}
	cout << ']' << endl;
}
