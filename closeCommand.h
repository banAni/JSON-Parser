#pragma once
#include "ACommand.h"
#include <string>
#include <fstream>
using namespace std;
class closeCommand :public ACommand {
	closeCommand() :ACommand(string("close")) {};
	void execute(JSON& json) {
		json.closeFile();
	}
};

