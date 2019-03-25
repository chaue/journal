#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "journal.h"
using namespace std;

void clearscreen();

int main() {
	string introans = "";
	Journal j = Journal();

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
}

void clearscreen() {
	cout << "\nPress Enter to continue: ";
	cin.ignore();
	if (system("CLS")) system("clear");
}