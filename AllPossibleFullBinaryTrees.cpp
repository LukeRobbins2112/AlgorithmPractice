
#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
 };
 

class Solution {
public:

	vector<TreeNode *> allPossibleFBT(int curN) {

		if (curN % 2 == 0) return {};
		if (curN == 0) return {};
		if (curN == 1) return { new TreeNode(0) };

		vector<TreeNode *> result;

		curN -= 1;

		for (int i = 1; i < curN; i += 2) {

			vector<TreeNode *> leftTrees = allPossibleFBT(i);
			vector<TreeNode *> rightTrees = allPossibleFBT(curN - i);

			for (auto l : leftTrees) {
				for (auto r : rightTrees) {
					TreeNode * root = new TreeNode(0);
					root->left = l;
					root->right = r;
					result.push_back(root);
				}
			}
		}

		return result;
	}

};

int main() {

	Solution s;
	int N = 7;
	vector<TreeNode *> result = s.allPossibleFBT(N);

	return 0;
}