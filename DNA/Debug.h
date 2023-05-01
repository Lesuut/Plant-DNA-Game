#pragma once

#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Debug
{
public:
	void Log(string str);
	void LogError(string str);
	void LogSystem(string str);

    string InsertRed(string str);
	string InsertGreen(string str);
	string InsertYellow(string str);
	string InsertBlue(string str);
	string InsertMagenta(string str);
	string InsertCyan(string str);
};
