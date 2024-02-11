#include "globals.h"

/*

  Given this linked list: 1->2->3->4->5
  For k = 2, you should return: 2->1->4->3->5
  For k = 3, you should return: 3->2->1->4->5

*/

// Recursive solution
ListNode* reverseKGroupRecursive(ListNode* head, int k) {
	ListNode* cursor = head;
	for(int i = 0; i < k; i++){
		if(cursor == nullptr) return head;
		cursor = cursor->next;
	}
	ListNode* curr = head;
	ListNode* prev = nullptr;
	ListNode* nxt = nullptr;
	for(int i = 0; i < k; i++){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	head->next = reverseKGroupRecursive(curr, k);
	return prev;
}

// Iterative solution
ListNode* reverseKGroupIterative(ListNode* head, int k) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* before = dummy;
	ListNode* after = head;
	ListNode* curr = nullptr;
	ListNode* prev = nullptr;
	ListNode* nxt = nullptr;
	while(true){
		ListNode* cursor = after;
		for(int i = 0; i < k; i++){
			if(cursor == nullptr) return dummy->next;
			cursor = cursor->next;
		}
		curr = after;
		prev = before;
		for(int i = 0; i < k; i++){
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		after->next = curr;
		before->next = prev;
		before = after;
		after = curr;
	}
}