#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Entry {
public:
	Entry();
	Entry(string date);
	void write();
	int read();
	template<typename T>
	void operator()(T input);
	void operator()(string input);
	void adddelim();
	bool checkcred(pair<string, string> p);
private:
	string filename;
	string fileinput;
	char delim;
};

class Journal {
public:
	Journal();
	Journal(pair<string, string> n);
	void printintro() const;
	void write();
	void read();
private:
	string name;
	pair<string, string> cred;
};