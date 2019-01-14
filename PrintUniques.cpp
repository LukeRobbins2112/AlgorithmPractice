#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

	int lowestUnique = INT_MAX;
	unordered_map<int, int> numCount;
	string line;

	while (getline(cin, line)) {

		stringstream ss(line);
		string element;
		int num;

		while (!ss.eof()) {
			ss >> element;
			num = atoi(element.c_str());
			numCount[num]++;
		}

		for (auto it : numCount) {
			if (it.second == 1) {
				lowestUnique = min(lowestUnique, it.second);
			}

		}

		cout << to_string(lowestUnique) << endl;
	}
}
