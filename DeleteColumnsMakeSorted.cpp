#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string>& A) {

		int result = 0;

		for (int j = 0; j < A[0].size(); j++) {
			for (int i = 1; i < A.size(); i++) {
				char top = A[i - 1][j];
				char bottom = A[i][j];
				if (top > bottom) {
					result++;
					break;
				}
			}
		}

		return result;

	}
};

int main() {
	Solution s;

	vector<string> input = { "rrjk","furt","guzm" };
	int result = s.minDeletionSize(input);

	return 0;
}