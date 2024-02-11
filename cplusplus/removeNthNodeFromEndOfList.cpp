#include "globals.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {

	// Two pointers, separated by n+1 nodes
	// When last pointer reaches the end, then other node is previous to the targeted node

	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* curr = dummy;
	ListNode* lead = dummy;

	// Advance pointer so it has a lead of n+1
	for(int i = 0; i < n+1; i++) {
		lead = lead->next;
	}

	// Maintain the gap, but move pointers one by one
	while(lead != NULL) {
		curr = curr->next;
		lead = lead->next;
	}
	// Next node is the targeted node
	curr->next = curr->next->next;

	// Do not return head pointer due to base case of [1]
	return dummy->next;
}