#pragma once
#include <string>
#include <vector>
#include "JSON.h"
using namespace std;
class ACommand {
protected:
	string commandName;
	vector<string> arguments;
	public:
		ACommand() {};
		ACommand(const string _commandName) : commandName(_commandName) {};
		virtual void execute(JSON&)=0;//JSON&
		inline void SetArgunets(vector<string> _arguments) { arguments = _arguments; }
};
