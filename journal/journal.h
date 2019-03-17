#include <iostream>
#include <string>
#include "entry.h"			// since we use entry objects in member functions
using namespace std;

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