#include <iostream>
#include <fstream>
#include <string>
#include "journal.h"
using namespace std;

int main() {

	string introans = "";

	Journal j = Journal();
	j.printintro();

	cout << "Enter option number: ";
	getline(cin, introans);
	if (introans == "1") {
		j.write();
	}
	else if (introans == "2") {
		j.read();
	}
	else {
		cout << introans << " was not an option.";
	}

	cout << "Done!";

	/*ofstream entry;
	entry.open("test.txt");
	if (entry.is_open()) {
		entry << "testing testing";
		entry.close();
	}
	else {
		cout << "error!";
	}*/
	
}