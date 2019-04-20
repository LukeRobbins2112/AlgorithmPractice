#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

	vector<string> commonChars(vector<string>& A) {

		int n = A.size();

		// Can optimize memory usage by re-using a sinle vector<int> count(26, 0)  within the loop and updating counts each time
		vector<vector<int>> charCounts(n, vector<int>(26, 0));

		for (int i = 0; i < n; i++) {

			string & s = A[i];
			for (char c : s) {
				charCounts[i][c - 'a']++;
			}
		}

		vector<int> counts(26, INT_MAX);
		for (auto vec : charCounts) {
			for (int i = 0; i < 26; i++) {
				counts[i] = min(counts[i], vec[i]);
			}
		}

		vector<string> result;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < counts[i]; j++) {
				char c = i + 'a';
				result.push_back(string(1, c));
			}
		}

		return result;
	}
};

int main() {

	vector<string> input = {
		"bella", "label", "roller"
	};

	Solution s;
	vector<string> result = s.commonChars(input);

	return 0;
}