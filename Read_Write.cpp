#include "Read_Write.h"
#include <iostream>
#include <limits>

using namespace std;

char GetUserChar() {
	char selection = ' ';
	cin >> selection;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return selection;
}
