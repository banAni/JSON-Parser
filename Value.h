#pragma once
#include <string>
using namespace std;
class Value {
	public:
		virtual void print() = 0;
		virtual void search(string&) = 0;
		virtual void printValue() = 0;
};
