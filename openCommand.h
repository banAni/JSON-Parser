#pragma once
#include "ACommand.h"
#include <string>
#include <fstream>
using namespace std;
class openCommand:public ACommand{
	openCommand() :ACommand(string("open")) {};
	void execute(JSON& json) {
		json.openFile();
	}
};
