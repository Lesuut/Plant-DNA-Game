#include "Debug.h"

using namespace std;

void Debug::Log(string str) {
	cout << str << endl;
}
void Debug::LogError(string str) {
	cout << "\033[1;31m" + str + "!" + "\033[0m" << endl;
}
void Debug::LogSystem(string str) {
	cout << "\033[1;33m" + str + "." + "\033[0m" << endl;
}

string Debug::InsertRed(string str) {
	return "\033[1;31m" + str + "\033[0m";
}
string Debug::InsertGreen(string str) {
	return "\033[1;32m" + str + "\033[0m";
}
string Debug::InsertYellow(string str) {
	return "\033[1;33m" + str + "\033[0m";
}
string Debug::InsertBlue(string str) {
	return "\033[1;34m" + str + "\033[0m";
}
string Debug::InsertMagenta(string str) {
	return "\033[1;35m" + str + "\033[0m";
}
string Debug::InsertCyan(string str) {
	return "\033[1;36m" + str + "\033[0m";
}
