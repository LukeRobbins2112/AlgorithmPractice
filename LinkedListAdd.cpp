
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int getSize(ListNode * node) {

	if (node == nullptr)
		return 0;

	ListNode * iter = node;
	int count = 0;

	while (iter) {
		count++;
		iter = iter->next;
	}

	return count;
}

ListNode * makeSameLength(ListNode* shortList, ListNode*  longList) {

	int len1 = getSize(shortList);
	int len2 = getSize(longList);

	if (len2 > len1) {

		ListNode * buff = new ListNode(0);
		ListNode * newStart = buff;
		len2--;

		while (len2 > len1) {
			buff->next = new ListNode(0);
			len2--;
		}
		buff->next = shortList;
		return newStart;
	}

	return shortList; // shorter list
}

int addNums(ListNode * l1, ListNode * l2) {

	if (l1 == nullptr || l2 == nullptr) {
		return 0;
	}

	int carry = addNums(l1->next, l2->next);
	l2->val = l2->val + l1->val + carry;

	carry = l2->val / 10;
	l2->val = l2->val % 10;

	return carry;

}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	// Add zero padding to ensure equal recursion depth
	l1 = makeSameLength(l1, l2);
	l2 = makeSameLength(l2, l1);

	int finalCarry = addNums(l1, l2);
	if (finalCarry > 0) {
		ListNode * newHead = new ListNode(finalCarry);
		newHead->next = l2;
		return newHead;
	}

	return l2;
}

int main()
{
	ListNode * n0 = new ListNode(9);
	ListNode * n1 = new ListNode(1);
	ListNode * n2 = new ListNode(6);
	ListNode * n3 = new ListNode(3);
	n0->next = n1;
	n1->next = n2;

	ListNode * n7 = new ListNode(0);

	ListNode * res = addTwoNumbers(n0, n7);


	return 0;
}

