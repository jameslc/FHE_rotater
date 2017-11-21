#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>
#include "Read_Write.h"

using namespace std;
//int const NUM_FAMILY_MEMBERS = 5;

int main() {
	vector<string> fheJobs;// {Music, Prayer_AoF, Activity, Snack, Lesson};
	vector<string> familyNames;
	ifstream readIn;
	ofstream save;
	char userResponse;
	string tempNames;
	string tempJobs;
	string otherTemp;
	stringstream ss;
	char menuSelection = ' ';
	char largerVector = '=';

	readIn.open("familyNames.txt");
	if (!readIn.is_open()) {
		cout << "File not Found" << endl;
		cout << "Would you like to create a new one? (y or n)" << endl;
		userResponse = GetUserChar();
		if (userResponse == 'y') {
			cout << "FIXME: add option to create new file." << endl;
		}
	}

	getline(readIn, tempNames);
	getline(readIn, tempJobs);
	readIn.close();

	ss.str(tempNames);
	while (!ss.eof()) {
		ss >> otherTemp;
		familyNames.push_back(otherTemp);
	}
	ss.clear();
	ss.str(tempJobs);
	while (!ss.eof()) {
		ss >> otherTemp;
		fheJobs.push_back(otherTemp);
	}

	ss.clear();

	if ((familyNames.size() == fheJobs.size())) {
		cout << "Welcome to the FHE rotator!" << endl;
	}
	else if (familyNames.size() >= fheJobs.size()) {
		cout << "Not enough jobs for everyone!" << endl;
		largerVector = 'n';
	}
	else if (familyNames.size() <= fheJobs.size()) {
		cout << "More jobs than people! Time to double up!" << endl;
		largerVector = 'j';
	}


	while (menuSelection != 'x') {
		cout << "Enter selection (O to see options): " << endl;
		cin >> menuSelection;

		switch (menuSelection) {
		case 'O':
		case 'o':
			//cout << "Enter the capitalized letter." << endl;
			cout << "o - display Options" << endl;
			cout << "r - Rotate jobs" << endl;
			cout << "d - Display current jobs" << endl;
			cout << "s - Save new configuration" << endl;
			cout << "p - add Person" << endl;
			cout << "j - add Job" << endl;
			cout << "x - eXit program." << endl;

			break;

		case 'R':
		case 'r':
			//otherTemp = fheJobs.at(0);
			fheJobs.insert(fheJobs.begin(), fheJobs.at(fheJobs.size() - 1));
			fheJobs.pop_back();
			//fheJobs.push_back(otherTemp);
			break;

		case 'D':
		case 'd':
			for (unsigned int i = 0; i < ((largerVector == 'n') ? familyNames.size() : fheJobs.size()); ++i) {
				if (i < familyNames.size()) {
					cout << setw(10) << left << familyNames.at(i);
				}
				cout << " - ";
				if (i < fheJobs.size()) {
					cout <<setw(10) << right << fheJobs.at(i);
				}
				cout << endl;
			}
			break;

		case 'S':
		case 's':
			save.open("familyNames.txt");
			if (!save.is_open()) {
				cout << "File creation unsuccessful." << endl;
			}
			for (unsigned int i = 0; i < familyNames.size(); ++i) {
				save << familyNames.at(i);
				if (i < familyNames.size() - 1) {
					save << " ";
				}
			}
			save << endl;
			for (unsigned int i = 0; i < fheJobs.size(); ++i) {
				save << fheJobs.at(i);
				if (i < familyNames.size() - 1) {
					save << " ";
				}
			}
			save << endl;
			break;

		case 'P':
		case 'p':
			cout << "Name of the new person?" << endl;
			cin >> otherTemp;
			familyNames.push_back(otherTemp);
			break;

		case 'J':
		case 'j':
			cout << "Name of the new job?" << endl;
			cin >> otherTemp;
			fheJobs.push_back(otherTemp);
			break;

		case 'X':
			menuSelection = 'x';
		case 'x':
			cout << "Goodbye!" << endl;
			break;

		default:
			cout << "Say what?!" << endl;
			break;
		}
	}

	
	return 0;
}