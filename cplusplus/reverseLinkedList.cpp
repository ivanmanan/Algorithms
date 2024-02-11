#include "globals.h"

// Reverse Linked List I
ListNode* reverseList(ListNode* head) {

	ListNode* prev = NULL;
	ListNode* curr = head;

	while(curr != NULL) {
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

// Reverse Linked List II
// Reverse a linked list from position m to n. Do it in one-pass.
// TODO: See Leetcode
// https://leetcode.com/problems/reverse-linked-list-ii