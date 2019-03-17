#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Entry {
public:
	Entry();
	Entry(string date);
	void write();
	template<typename T>
	void operator()(T input);
	void operator()(string input);
	void adddelim();
private:
	string filename;
	string fileinput;
	string delim;
};

class Journal {
public:
	Journal();
	Journal(string n);
	void printintro() const;
	void write();
	void read();
private:
	string name;
};