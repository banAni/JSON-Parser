#pragma once
#include "ACommand.h"
#include <string>
#include <fstream>
using namespace std;
class helpCommand :public ACommand {
	helpCommand() :ACommand(string("help")) {};
	void execute(JSON& json) {
		json.help();
	}
};
