#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

	void PrintVec(const vector<int> & vec) {
		cout << "Vector: {";
		for (int i : vec) {
			cout << i << " ";
		}
		cout << "}" << endl;
	}

	vector<int> sortedSquares(vector<int>& A) {

		int posBegin = 0;
		for (; posBegin < A.size(); posBegin++) {
			if (A[posBegin] >= 0) {
				std::reverse(begin(A), begin(A) + posBegin);
				break;
			}
		}

		std::transform(begin(A), end(A), begin(A), [](int n) {return n * n; });
		int negPtr = 0, posPtr = posBegin;

		vector<int> result(A.size());

		int i = 0, j = posBegin, k = 0;

		while (i < posBegin && j < A.size()) {
			if (A[i] < A[j]) {
				result[k++] = A[i];
				i++;
			}
			else {
				result[k++] = A[j];
				j++;
			}
		}

		while (i < posBegin) result[k++] = A[i++];
		while (j < A.size()) result[k++] = A[j++];

		PrintVec(result);

		return result;
	}
};

int main() {

	vector<int> input = { -4, -1, 0, 3, 10 };
	Solution s;

	vector<int> result = s.sortedSquares(input);

	return 0;

}