
#include <vector>
#include <algorithm>

using namespace std;

bool stoneGame(vector<int>& p) {
	int n = p.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		dp[i][i] = p[i];
	}

	for (int d = 1; d < n; d++)
		for (int i = 0; i < n - d; i++) {
			int first = p[i] - dp[i + 1][i + d];
			int second = p[i + d] - dp[i][i + d - 1];
			dp[i][i + d] = max(first, second);
		}
			
	return dp[0][n - 1] > 0;
}

int main() {

	vector<int> input = { 5, 3, 4, 5 };
	bool result = stoneGame(input);

	return 0;

}