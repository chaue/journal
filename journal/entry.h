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
	void adddelim() ;
private:
	string filename;
	string fileinput;
	string delim;
};