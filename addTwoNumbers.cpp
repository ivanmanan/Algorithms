/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode* head = NULL;
	ListNode* Cur;
	ListNode* Nex;
	int carry = 0;
	int sum = 0;

	while(l1 != NULL || l2 != NULL) {

		sum = carry;
		if(l1 != NULL) {
			sum += l1->val;
			l1 = l1->next;
		}
		if(l2 != NULL) {
			sum += l2->val;
			l2 = l2->next;
		}

		int digit = sum % 10;
		carry = sum / 10;
		Nex = new ListNode(digit);

		if(head == NULL) {
			head = Nex;
		}
		else {
			Cur->next = Nex;
		}
		Cur = Nex;
	}

	if(carry != 0) {
		Nex = new ListNode(carry);
		Cur->next = Nex;
	}
	return head;
}
};