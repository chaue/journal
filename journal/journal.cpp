#include "journal.h"

Journal::Journal() {
	name = "Journal";
}

Journal::Journal(string n) {
	name = n;
}

void Journal::printintro() const {
	cout << "***************\n";
	cout << "*   Journal   *\n";
	cout << "***************\n";
	cout << "Select an option\n";
	cout << "----------------\n";
	cout << "1. Write\n";
	cout << "2. Read\n";
}

void Journal::write() {
	string date;
	int mood;
	string content;
	// instantiate entry object
	cout << "----------------\n";
	cout << "Enter the date: ";
	// entry.getdate();
	cout << "Rate from 1 to 10";
	// entry.getmood();
	cout << "Write entry:";
	// entry.write();
}

void Journal::read() {
	string date;
	// instantiate entry object based on date
	// entry.read();
}