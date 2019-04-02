
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int n = s.size();
		if (n < 2) return n;

		vector<int> lastCharPos(256, -1);
		int first = 0;
		int last = 0;
		int curMax = 0;
		int longest = 0;

		while (last < n) {

			int lastOccurrence = lastCharPos[s[last]];

			if (lastOccurrence >= 0) {
				while (first <= lastOccurrence) {
					lastCharPos[s[first]] = -1;
					first++;
				}
				lastCharPos[s[last]] = last;
			}
			else {
				lastCharPos[s[last]] = last;
				curMax = (last - first) + 1;
				longest = max(longest, curMax);
			}
			last++;
		}

		return longest;
	}
};

int main() {

	string input1 = "abcabcbb";
	string input2 = "bbbbb";
	string input3 = "pwwkew";

	Solution s;
	int len1 = s.lengthOfLongestSubstring(input1);
	int len2 = s.lengthOfLongestSubstring(input2);
	int len3 = s.lengthOfLongestSubstring(input3);

	return 0;
}