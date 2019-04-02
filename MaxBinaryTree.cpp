
#include <vector>

using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:

	TreeNode * maxTree(vector<int> & nums, int begin, int end) {

		if (begin < 0 || begin > end || end > nums.size()) return nullptr;

		// Get max val position
		int maxPos = begin;
		for (int i = begin; i <= end; i++) {
			maxPos = (nums[maxPos] > nums[i]) ? maxPos : i;
		}

		TreeNode * root = new TreeNode(nums[maxPos]);
		root->left = maxTree(nums, begin, maxPos - 1);
		root->right = maxTree(nums, maxPos + 1, end);

		return root;
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return maxTree(nums, 0, nums.size() - 1);
	}
};

int main() {

	Solution s;
	vector<int> nums = { 3, 2, 1, 6, 0, 5 };
	TreeNode * result = s.constructMaximumBinaryTree(nums);

	return 0;

}