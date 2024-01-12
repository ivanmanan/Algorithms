#include "globals.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode* head = NULL;
	ListNode* curr = NULL;
	ListNode* next = NULL;

	ListNode* p = l1;
	ListNode* q = l2;

	int carry = 0;
	while(p != NULL || q != NULL) {
		int sum = carry;

		if(p != NULL) {
			sum += p->val;
			p = p->next;
		}
		if(q != NULL) {
			sum += q->val;
			q = q->next;
		}

		int digit = sum % 10;
		carry = sum / 10;

		if(head == NULL) {
			head = new ListNode(digit);
			curr = head;
		}
		else {
			next = new ListNode(digit);
			curr->next = next;
			curr = curr->next;
		}
	}

	// Check remaining carry
	if(carry != 0) {
		next = new ListNode(carry);
		curr->next = next;
	}

	return head;
}
