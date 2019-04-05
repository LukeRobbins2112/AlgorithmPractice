#include <vector>
#include <string>

using namespace std;

/*
** Problem Description**

We are given an array A of N lowercase letter strings, all of the same length.
Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, 
then the final array after deletions is ["bef", "vyz"], and the remaining columns of A are ["b","v"], ["e","y"], and ["f","z"].  
(Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]].)

Suppose we chose a set of deletion indices D such that after deletions, each remaining column in A is in non-decreasing sorted order.

Return the minimum possible value of D.length.
*/

class Solution {
public:
	int minDeletionSize(vector<string>& A) {

		if (A.size() < 2) return 0;     // if empty or a single row (default sorted cols)

		int result = 0;
		int rows = A.size();
		int cols = A[0].size();

		for (int j = 0; j < cols; j++) {
			for (int i = 1; i < rows; i++) {
				if (A[i][j] < A[i - 1][j]) {
					result++;
					break;
				}
			}
		}

		return result;
	}
};


int main() {

	vector<string> input = { "cba","daf","ghi" };
	Solution s;

	int result = s.minDeletionSize(input);

	return 0;

}