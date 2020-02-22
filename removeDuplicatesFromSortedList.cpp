#include "globals.h"

ListNode* deleteDuplicates(ListNode* head) {

	ListNode* curr = head;

	while(curr != NULL && curr->next != NULL) {

		if(curr->val == curr->next->val) {
			curr->next = curr->next->next;
		}
		else {
			curr = curr->next;
		}
	}
	return head;
}