#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:

	bool isSelfDividing(int num) {

		int numCopy = num;

		while (numCopy > 0) {
			int divisor = numCopy % 10;  // Get next digit

			if (divisor == 0 || num % divisor != 0)
				return false;

			numCopy /= 10;          // Remove used digit of work number
		}

		return true;
	}

	vector<int> selfDividingNumbers(int left, int right) {

		vector<int> result;

		for (int i = left; i <= right; i++) {
			if (isSelfDividing(i))
				result.push_back(i);
		}

		return result;
	}
};

int main() {

	int left = 1, right = 101;
	Solution s;
	vector<int> result = s.selfDividingNumbers(left, right);

	cout << "Self Dividing Numbers: " << endl;
	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;

	return 0;

}