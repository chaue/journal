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
	int rating;
	string text;
	cout << "--------------------------\n";
	cout << "Enter the date (mmddyy): ";
	getline(cin, date);				// could add user input validation later
	Entry e(date);			// assume correct input for now

	while (true) {
		cout << "Rate from 1 to 10: ";
		cin >> rating;
		cin.clear();
		if (rating > 0 && rating < 11) {	// check if input is between 1 to 10
			e(rating);						// break loop if it is, stay in loop if not
			e.adddelim();				
			break;
		}
		else {
			cout << "\n";
		}
	}

	cout << "Write entry (Enter \"end\" on new line to finish: \n";
	while (text != "end") {
		int count = 1;
		cout << "Line " << count << ": ";
		getline(cin, text);
		e(text);
		e.adddelim();
		count++;
	}

	e.write();
}

void Journal::read() {
	string date;
	cout << "not coded yet :/";
	// instantiate entry object based on date
	// entry.read();
}