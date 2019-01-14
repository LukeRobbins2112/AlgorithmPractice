#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool validateParens(string line) {

	string oParens = "({[";
	string cParens = ")}]";

	stack<char> openParens;

	for (char c : line) {
		if (oParens.find(c) != string::npos) {
			openParens.push(c);
		}
		else if (cParens.find(c) != string::npos) {

			if (openParens.empty())
				return false;

			char open = openParens.top();
			openParens.pop();

			switch (c) {
			case ')':
				if (open != '(')
					return false;
				break;
			case '}':
				if (open != '{')
					return false;
				break;
			case ']':
				if (open != '[')
					return false;
				break;
			default:
				break;
			}
		}
		else {
			return false;   // Shouldn't happen, but...
		}
	}

	return true;
}

int main() {



	string line;
	while (getline(cin, line)) {

		bool result = validateParens(line);
		string output = (result == true) ? "True" : "False";
		cout << output << endl;

	}
}
