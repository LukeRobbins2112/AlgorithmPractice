
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {

		if (s.size() < 2) return s;
		int n = s.size();

		vector<vector<bool>> dp(n, vector<bool>(n, false));

		string longest = "";

		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				dp[i][j] = ((s[i] == s[j]) && (j - i < 3 || dp[i + 1][j - 1] == true));
				if (dp[i][j] == true) {
					longest = ((j - i + 1) >= longest.size()) ? s.substr(i, j - i + 1) : longest;
				}
				else {
					//break;
				}
			}
		}

		return longest;
	}
};

int main() {

	Solution s;
	string str = "kdfsdfyshhsyfsda";

	string res = s.longestPalindrome(str);

	return 0;

}