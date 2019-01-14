
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
	bool isPalindrome(ListNode* head) {

		if (!head || !head->next) return true;

		// Get a pointer to the second half of the list
		ListNode * slow = head;
		ListNode * fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		// Reverse the second half of the list
		ListNode * rightHalf = reverseList(slow);

		// Compare two lists
		ListNode * leftHalf = head;

		while (rightHalf && leftHalf) {
			if (rightHalf->val != leftHalf->val) return false;
			rightHalf = rightHalf->next;
			leftHalf = leftHalf->next;
		}

		return true;

	}

	ListNode * reverseList(ListNode * head) {

		if (!head) return nullptr;

		ListNode * prev = nullptr;
		ListNode * cur = head;
		ListNode * next = head->next;

		while (cur) {
			cur->next = prev;
			prev = cur;
			cur = next;
			next = (next) ? next->next : nullptr;
		}

		return prev;
	}
};

int main() {
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(1);
	ListNode * l3 = new ListNode(2);
	ListNode * l4 = new ListNode(1);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	
	Solution s;
	bool result = s.isPalindrome(l1);

	return 0;
}