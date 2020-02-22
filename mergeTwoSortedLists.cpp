#include "globals.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = NULL;
	ListNode* curr = NULL;
	ListNode* next = NULL;

	// Create head node
	if(l1 == NULL || l2 == NULL) {
		if(l1 == NULL && l2 == NULL) {
			return head;
		}
		else if(l1 == NULL) {
			head = new ListNode(l2->val);
			l2 = l2->next;
		}
		else {
			head = new ListNode(l1->val);
			l1 = l1->next;
		}
	}
	else if(l1->val > l2->val) {
		head = new ListNode(l2->val);
		l2 = l2->next;
	}
	else {
		head = new ListNode(l1->val);
		l1 = l1->next;
	}

	curr = head;

	while(l1 != NULL || l2 != NULL) {
		if(l1 == NULL) {
			next = new ListNode(l2->val);
			l2 = l2->next;
		}
		else if(l2 == NULL) {
			next = new ListNode(l1->val);
			l1 = l1->next;
		}
		else if(l1->val > l2->val) {
			next = new ListNode(l2->val);
			l2 = l2->next;
		}
		else {
			next = new ListNode(l1->val);
			l1 = l1->next;
		}
		curr->next = next;
		curr = curr->next;
	}
	return head;
}