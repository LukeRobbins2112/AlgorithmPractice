
#include <vector>

using namespace std;

class Solution {
public:

	void findRectangle(vector<vector<int>> & grid, int r, int c) {

		int rows = grid.size();
		int cols = grid[0].size();

		for (int i = r + 1; i < rows; i++) {
			if (grid[i][c] == 1) {
				for (int j = c + 1; j < cols; j++) {
					if (grid[r][j] == 1 && grid[i][j] == 1) {
						result++;
					}
				}
			}
		}


	}

	int countCornerRectangles(vector<vector<int>>& grid) {

		int rows = grid.size();
		int cols = grid[0].size();

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 1) {
					findRectangle(grid, i, j);
				}
			}
		}

		return result;
	}

private:
	int result = 0;
};

int main() {

	Solution s;
	vector<vector<int>> input = {
		{0, 1, 0},
		{1, 0, 1},
		{1, 0, 1},
		{0, 1, 0}
	};

	int result = s.countCornerRectangles(input);

	return 0;
}