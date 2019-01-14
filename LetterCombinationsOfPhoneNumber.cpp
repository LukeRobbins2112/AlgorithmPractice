#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

	vector<string> buttons = {
		"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
	};

	void recLetterComb(vector<string> & result, string curString, string & digits, int pos) {

		if (pos == digits.size()) {
			result.push_back(curString);
			return;
		}

		for (char c : buttons[digits[pos]-'0']) {
			recLetterComb(result, curString + c, digits, pos + 1);
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> result;
		recLetterComb(result, "", digits, 0);
		return result;
	}
};

int main() {

	string s = "23";
	Solution sol;
	vector<string> result = sol.letterCombinations(s);

	return 0;

}