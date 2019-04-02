
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {

		int rows = A.size();
		int cols = A[0].size();

		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		for (int j = 0; j < cols; j++) dp[rows - 1][j] = A[rows - 1][j];

		for (int i = rows - 2; i >= 0; i--) {
			for (int j = 0; j < cols; j++) {
				int left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
				int center = dp[i + 1][j];
				int right = (j < cols - 1) ? dp[i + 1][j + 1] : INT_MAX;

				dp[i][j] = min({ left, center, right }) + A[i][j];
			}
		}

		int result = dp[0][0];
		for (int j = 1; j < cols; j++) {
			result = min(result, dp[0][j]);
		}

		return result;
	}
};

int main() {

	vector<vector<int>> input = { {123}, {456}, {789} };
	Solution s;
	int result = s.minFallingPathSum(input);

	return 0;
}