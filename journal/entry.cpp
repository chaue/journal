#include "entry.h"

Entry::Entry() {
	filename = "";
	fileinput = "";
	string delim = "";
}

Entry::Entry(string date) {
	filename = date;
	fileinput = "";
	string delim = "|";
}

void Entry::write() {
	ofstream file;
	file.open(filename);				// create new file
	file << "/" << fileinput << "/";	// write the input from journal.write() to the file
	file.close();
}

template<typename T>
void Entry::operator()(T input) {		// takes both numeric and string input
	fileinput = fileinput + to_string(input);
}

void Entry::adddelim() {				// add delimiter after each text section
	fileinput = fileinput + delim;
}