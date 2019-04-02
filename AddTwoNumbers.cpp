

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		if (!l1) return l2;
		if (!l2) return l1;

		ListNode * dummy = new ListNode(-1);
		ListNode * iter = dummy;
		int carry = 0;

		while (l1 || l2) {
			int currSum = carry;
			currSum += (l1) ? l1->val : 0;
			currSum += (l2) ? l2->val : 0;

			int nodeVal = currSum % 10;
			carry = currSum / 10;

			iter->next = new ListNode(nodeVal);

			iter = iter->next;
			l1 = (l1) ? l1->next : nullptr;
			l2 = (l2) ? l2->next : nullptr;
		}

		if (carry == 1) iter->next = new ListNode(1);

		ListNode * res = dummy->next;
		delete dummy;
		return res;

	}
};


int main() {
	ListNode * a1 = new ListNode(2);
	ListNode * a2 = new ListNode(4);
	ListNode * a3 = new ListNode(3);
	a1->next = a2;
	a2->next = a3;
	a3->next = nullptr;

	ListNode * b1 = new ListNode(5);
	ListNode * b2 = new ListNode(6);
	ListNode * b3 = new ListNode(4);
	b1->next = b2;
	b2->next = b3;
	b3->next = nullptr;

	Solution s;
	ListNode * res = s.addTwoNumbers(a1, b1);

	return 0;
}