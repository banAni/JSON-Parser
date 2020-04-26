#pragma once
#include<string>
#include <fstream>
#include "Value.h"
#include "Array.h"
#include "String.h"
#include "Number.h"
#include "Object.h"
#include<sstream>
using namespace std;
class JSON {
private:
	 string json;
     stringstream JsON;
     string fileName;
     bool isFileOpened;
	 Array* readArray(stringstream&);
	 Value* readValue(stringstream&);
	 Number* readNumber(stringstream&);
	 string readString(stringstream&);
     //helper functions
     inline bool exists(const string name);
     inline bool isWhiteSpace(char expr);
     void readWhiteSpace(stringstream&);
     inline bool isDigit(char expr);
     inline bool isOperation(char expr);
public:
     //file functions
     void openFile();
     void closeFile();
     void saveFile();
     void saveAsFile();
     void help();

     JSON();
     bool validateJSON();
     void printJSON();
     bool searchJSON(string&);
     void setJSON();
     void createJSON();
     void deleteJSON();

};
inline bool JSON::isOperation(char expr) {
    return expr == '+' || expr == '-';
}
inline bool JSON::isDigit(char expr) {
    return expr >= '1' && expr <= '9';
}
inline bool JSON::isWhiteSpace(char expr) {
    return expr == ' ' || expr == '|' || expr == '/n';
}
void JSON::help() {
    cout
        << " - Commands - - ----------- Info -----------" <<endl
        << "The following commands are supported :" << endl
        << "open <file>	      opens <file>" << endl
        << "close			  closes currently opened file" << endl
        << "save			  saves the currently open file" << endl
        << "saveas <file>	  saves the currently open file in <file>" << endl
        << "help			  prints this information" << endl;
}
void JSON::printJSON() {
    if (!isFileOpened) {
        cout << "No opened file found. Please, first open a file by using the Open command.";
    }
    //TO_DO
}
void JSON::saveFile() {
    if (!isFileOpened) {
        cout<< "No opened file found. Please, first open a file by using the Open command.";
    }
    //TO-DO
}
void JSON::saveAsFile() {
    if (!isFileOpened) {
        cout << "No opened file found. Please, first open a file by using the Open command.";
    }
    //TO-DO
}
void JSON::closeFile() {
    if (isFileOpened) {
        fileName.clear();
        //iztrivane na string
        cout << "Successfully closed " << fileName <<endl;
        isFileOpened = false;
    }
    else {
        cout << "No opened file found. Please, first open a file by using the Open command.";
    }
}
inline bool JSON::exists(const string name) {
    ifstream f(name.c_str());
    return f.good();
}
void JSON::openFile() {
    cout << "Enter file name:";
    cin >> fileName;
    if (!exists(fileName)) {
        ifstream file(fileName);
    }
    ifstream file(fileName);
    if (!file) {
        cout << "Couldn't open file for reading!" << endl;
    }
    getline(file, json);
    //stringstream json(helperJson);
    JsON << json;
    file.close();
    cout << "Successfylly opened " << fileName << endl;
    cout << "available commands";
    isFileOpened = true;
}
string JSON::readString(stringstream& jsonStream) {
    if (jsonStream.get() != '"') {
        cout << "It's not starting with \" ";
    }
    char symbol = jsonStream.get();
    vector<char> key;
    while (symbol != '"') {
        key.push_back(symbol);
        symbol = jsonStream.get();
    }
    return string(key.begin(), key.end());
}
/*Array* JSON::readArray(stringstream& jsonStream) {
    char symbol = jsonStream.get();
    if (symbol != '[') {
        cout<<" It's not starting with '[' ";
    }
    readWhitespace(jsonStream);
    symbol = jsonStream.peek();
    if (symbol == ']') {
        jsonStream.get();
        return new Array();
    }
    vector<Value*> arrayValue;

    do {
        arrayValue.push_back(Value(jsonStream));
        symbol = jsonStream.get();
    } while (symbol == ',');

    if (symbol != ']') {
        cout<<"Expected : ']'";
    }
    return new Array(arrayValue);
}
*/
