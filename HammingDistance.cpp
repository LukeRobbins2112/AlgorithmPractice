#include <assert.h>
#include <intrin.h>

/*
** Problem Description **

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
*/

class Solution {
public:
	int hammingDistance(int x, int y) {

		int result = 0;

		int diffBits = x ^ y;

		while (diffBits > 0) {
			diffBits &= (diffBits - 1);
			result++;
		}

		return result;
	}
};

int main() {

	int x = 34854;
	int y = 8251;

	Solution s;
	int result = s.hammingDistance(x, y);
	int check = __popcnt(x ^ y);
	assert(result == check);

	return 0;
}