#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ofstream entry;
	entry.open("test.txt");
	if (entry.is_open()) {
		entry << "testing testing";
		entry.close();
	}
	else {
		cout << "error!";
	}
}