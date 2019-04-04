#include <vector>
#include <string>

using namespace std;

/*
** Problem Description **

Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
*/


class Solution {
public:
	vector<int> diStringMatch(string S) {

		int iNum = 0;
		int dNum = S.size();
		int index = 0;

		vector<int> result(S.size() + 1);

		for (char c : S) {
			if (c == 'I') {
				result[index++] = (iNum++);
			}
			else {
				result[index++] = (dNum--);
			}
		}

		result[S.size()] = (dNum);
		return result;
	}
};

int main() {

	string input = "DIDDDIDIDDIDIDID";
	Solution s;
	vector<int> result = s.diStringMatch(input);

	return 0;

}