
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode * merge(ListNode * la, ListNode * lb) {

	ListNode * minStart = (la->val < lb->val) ? la : lb;
	ListNode * temp;

	while (la != nullptr && lb != nullptr) {

		if (la->val < lb->val) {
			while (la && la->next && la->next->val < lb->val) {
				la = la->next;
			}
			temp = la;
			la = la->next;
			temp->next = lb;
		}
		else {
			while (lb && lb->next && lb->next->val < la->val) {
				lb = lb->next;
			}
			temp = lb;
			lb = lb->next;
			temp->next = la;
		}
	}

	return minStart;

}

ListNode * splitList(ListNode * head) {
	ListNode * fast = head;
	ListNode * slow = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	while (head && head->next->val != slow->val) {
		head = head->next;
	}
	head->next = nullptr;

	return slow;
}

ListNode * mergeSort(ListNode * head) {

	if (head->next == nullptr)
		return head;

	ListNode * la = head;
	ListNode * lb = splitList(la);

	la = mergeSort(la);
	lb = mergeSort(lb);
	ListNode * res = merge(la, lb);

	return res;
}

ListNode* sortList(ListNode* head) {

	return mergeSort(head);
}

int main()
{

	ListNode * a = new ListNode(-1);
	ListNode * b = new ListNode(5);
	ListNode * c = new ListNode(3);
	ListNode * d = new ListNode(4);

	ListNode * e = new ListNode(0);
	ListNode * f = new ListNode(6);
	ListNode * g = new ListNode(7);
	ListNode * h = new ListNode(8);

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	ListNode * res = sortList(a);

	return 0;
}

