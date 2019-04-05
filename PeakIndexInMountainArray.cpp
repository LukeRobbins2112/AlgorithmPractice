#include <vector>
using namespace std;


/*
** Problem Description **

Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

*/


class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {

		int low = 0, high = A.size() - 1;

		while (low <= high) {
			int mid = (low + (high - low) / 2);

			// Ends of array
			if (mid == 0) {
				if (A[mid] > A[mid + 1]) return mid;
			}
			else if (mid == A.size() - 1) {
				if (A[mid] > A[mid - 1]) return mid;
			}

			// General comparisons
			if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) {
				low = mid + 1;
			}
			else if (A[mid - 1] > A[mid] && A[mid] > A[mid + 1]) {
				high = mid - 1;
			}
			else {
				return mid;
			}
		}

		return -1;
	}
};

int main() {

	vector<int> input1 = { 1, 3, 6, 8, 9, 5, 2 };		// Good peak array
	vector<int> input2 = { 1, 4, 6, 9 };			// Degenerate case - all increasing
	vector<int> input3 = { 6, 4, 2, 1 };			// Degenerate case - all decreasing

	Solution s;

	int result1 = s.peakIndexInMountainArray(input1);
	int result2 = s.peakIndexInMountainArray(input2);
	int result3 = s.peakIndexInMountainArray(input3);


}