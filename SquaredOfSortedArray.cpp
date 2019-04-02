#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

	vector<int> sortedSquares(vector<int>& A) {

		vector<int> result(A.size());

		// Work from the outside in
		int left = 0, right = A.size() - 1;

		// Fill in result array from the end (largest vals) to the beginning (smallest vals)
		for (int ptr = right; ptr >= 0; ptr--) {

			int negSquare = A[left] * A[left];
			int posSquare = A[right] * A[right];

			// Take max of the two squares, and update the winner's pointer
			if (negSquare >= posSquare) {
				result[ptr] = negSquare;
				left++;
			}
			else {
				result[ptr] = posSquare;
				right--;
			}
		}

		return result;
	}
};

int main() {

	vector<int> input = { -4, -1, 0, 3, 10 };
	Solution s;

	vector<int> result = s.sortedSquares(input);

	return 0;

}