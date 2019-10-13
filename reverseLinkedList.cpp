ListNode* reverseList(ListNode* head) {

	ListNode* Cur = head;
	ListNode* Prev = NULL;
	ListNode* Nex;

	while(Cur != NULL) {
		Nex = Cur->next;
		Cur->next = Prev;
		Prev = Cur;
		Cur = Nex;
	}
	return Prev;
	/*
	  Cannot return ListNode* head here
	  --> head only points to the last element of the newly
	      reversed linked list
	 */
}