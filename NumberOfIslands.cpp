#include <vector>

using namespace std;


class Solution {
public:

	void dfs(vector<vector<char>> & grid, int i, int j) {

		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') return;

		grid[i][j] = '0';

		dfs(grid, i + 1, j);
		dfs(grid, i, j + 1);
		dfs(grid, i - 1, j);
		dfs(grid, i, j - 1);
	}

	int numIslands(vector<vector<char>>& grid) {

		if (grid.empty()) return 0;

		int result = 0;
		int rows = grid.size();
		int cols = grid[0].size();

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == '1') {
					result++;
					dfs(grid, i, j);
				}
			}
		}

		return result;
	}
};

int main() {

	Solution s;
	vector<vector<char>> input = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	};

	int result = s.numIslands(input);

	return 0;
}