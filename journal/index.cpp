#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include "journal.h"
using namespace std;

void clearscreen();
pair<string, string> checklogin();
string getpass();

int main() {
	string introans = "";
	pair<string, string> logininfo;
	logininfo = checklogin();

	if (system("CLS")) system("clear");
	Journal j = Journal(logininfo);

	while (true) {
		j.printintro();
		cout << "Enter option number: ";
		getline(cin, introans);
		if (introans == "1") {
			j.write();
		}
		else if (introans == "2") {
			j.read();
		}
		else if (introans == "3") {
			break;
		}
		else {
			cout << introans << " was not an option.";
		}
		clearscreen();
	}

	return 0;
}

string getpass() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	string s;
	getline(cin, s);

	// leave hide input
	SetConsoleMode(hStdin, mode);
	return s;
}

void clearscreen() {
	cout << "\nPress Enter to continue: ";
	cin.ignore();
	if (system("CLS")) system("clear");
}

pair<string, string> checklogin() {
	fstream login;
	string user = "";
	string pass = "";

	while (true) {
		cout << "Enter your username: ";
		getline(cin, user);
		cout << "Enter your password: ";
		pass = getpass();

		login.open("login.txt");
		if (login.peek() == std::ifstream::traits_type::eof()) {		// if file is empty
			login << user + "|" + pass + "|\n";
			return pair<string, string>(user, pass);
		}
		else {
			string both = user + "|" + pass;
			string input;
			while (getline(login, input)) {
				if (input == both) {
					return pair<string, string>(user, pass);
				}
				cout << "Combination not found. \n";
			}
		}
	}
}
