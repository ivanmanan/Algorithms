#include "globals.h"

ListNode* middleNode(ListNode* head) {
	ListNode* lead = head;
	ListNode* curr = head;

	while(lead != NULL && lead->next != NULL) {
		lead = lead->next->next;
		curr = curr->next;
	}
	return curr;
}