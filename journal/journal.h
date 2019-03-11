#include <iostream>
#include <string>
using namespace std;

class Journal {
public:
	Journal();
	void printintro() const;
private:
	string name;
	string intro;
};