#include "globals.h"

// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

// Given:  12->11->12->21->41->43->21
// Output: 12->11->21->41->43

// Solution with O(1) space, O(N^2) time exists with two loops
// O(N) space, O(N) time
ListNode* removeDuplicates(ListNode* head) {

	ListNode* curr = head;
	ListNode* prev = NULL;

	unordered_set<int> nums;

	while(curr != NULL) {
		auto got = nums.find(curr->val);

		// Node contains duplicate
		if(got != nums.end()) {
			prev->next = curr->next;
			ListNode* temp = curr;
			curr = curr->next;
			delete temp;
		}
		else {
			nums.insert(curr->val);
			prev = curr;
			curr = curr->next;
		}
	}

	return head;
}

int main() {

	const int NUMS_SIZE = 7;
	const int ANS_SIZE = 5;
	int nums[NUMS_SIZE] = {12, 11, 12, 21, 41, 43, 21};
	int ans[ANS_SIZE]  = {12, 11, 21, 41, 43};

	ListNode* head = new ListNode(12);
	ListNode* temp = head;

	for(int i = 1; i < NUMS_SIZE; i++) {
		ListNode* nex = new ListNode(nums[i]);
		temp->next = nex;
		temp = temp->next;
	}
	head = removeDuplicates(head);

	ListNode* curr = head;
	cout << "Output:   ";
	while(curr != NULL) {
		cout << curr->val;
		if(curr->next != NULL) {
			cout << "->";
		}
		curr = curr->next;
	}
	cout << endl;
	cout << "Expected: ";
	for(int i = 0; i < ANS_SIZE; i++) {
		cout << ans[i];
		if(i != ANS_SIZE-1) {
			cout << "->";
		}
	}
	cout << endl;

	curr = head;
	while(curr != NULL) {
		ListNode* temp = curr;
		curr = curr->next;
		delete temp;
	}
}