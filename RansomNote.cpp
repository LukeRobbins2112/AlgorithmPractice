#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {

	char letters[256] = { 0 };
	string magLetters = "";

	string note;
	string numMagsStr;
	int numMags;
	string currentMag;

	getline(cin, note);
	getline(cin, numMagsStr);
	numMags = atoi(numMagsStr.c_str());

	for (int i = 0; i < numMags; i++) {
		getline(cin, currentMag);
		magLetters += currentMag;
	}


	for (char c : magLetters)
		letters[c - 'a']++;

	// Now check if the magazine letters 
	// provide enough for the note

	for (char c : note) {

		if (c != ' ')
			letters[c - 'a']--;

		if (letters[c - 'a'] < 0) {
			cout << "false" << endl;
			break;
		}
	}

	cout << "true" << endl;

}
