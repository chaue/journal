#include <iostream>
#include <fstream>
#include <string>
#include "journal.h"
using namespace std;

int main() {

	Journal j = Journal();
	j.printintro();

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