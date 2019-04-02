
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

	int countSubstrings(string s) {
		if (s.empty()) return 0;
		if (s.size() == 1) return 1;

		int n = s.size();
		int result = 0;

		vector<vector<bool>> dp(n, vector<bool>(n, false));

		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				dp[i][j] = (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1] == true));
				if (dp[i][j])
					result++;

			}
		}

		return result;
	}


};

int main() {

	string str = "aaaaa";
	Solution s;

	int result = s.countSubstrings(str);

	return 0;
}