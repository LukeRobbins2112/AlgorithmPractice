
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

		if (t1 == nullptr && t2 == nullptr) return nullptr;

		int t1Val = (t1 ? t1->val : 0);
		int t2Val = (t2 ? t2->val : 0);

		TreeNode * newNode = new TreeNode(t1Val + t2Val);
		newNode->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
		newNode->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);

		return newNode;
	}
};

int main() {

	TreeNode * tA_root = new TreeNode(3);
	TreeNode * tA_1 = new TreeNode(1);
	TreeNode * tA_2 = new TreeNode(2);
	TreeNode * tA_3 = new TreeNode(5);
	tA_root->left = tA_1;
	tA_root->right = tA_2;
	tA_1->left = tA_3;


	TreeNode * tB_root = new TreeNode(1);
	TreeNode * tB_1 = new TreeNode(4);
	TreeNode * tB_2 = new TreeNode(2);
	TreeNode * tB_3 = new TreeNode(5);
	TreeNode * tB_4 = new TreeNode(3);
	TreeNode * tB_5 = new TreeNode(7);
	tB_root->left = tB_1;
	tB_root->right = tB_2;
	tB_1->right = tB_3;
	tB_2->left = tB_4;
	tB_2->right = tB_5;

	Solution s;

	TreeNode * result = s.mergeTrees(tA_root, tB_root);

	return 0;
}