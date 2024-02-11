/*
TWO POINTERS

i, j
i += 1 node at at a time
j += 2 nodes at a time

i -> half
j -> end (also track size)

Set j=0, while i=halfway

If even size:
[1] -> [2] -> [2] -> [1]
                i=2           j=2

If odd size:
[1] -> [2] -> [3] -> [2] -> [1]
                i=3                  j=3

First half of list: [1] -> [2] -> [3]
Second half of list: [3] -> [2] -> [1]

[1] -> [2]
[1] -> [2] -> [3]



*/
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
    }

    // Reverse list
    ListNode* curr = slow;
    ListNode* prev = NULL;
    ListNode* nex = NULL;
    while(curr != NULL) {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    ListNode* p = head;
    ListNode* q = prev;
    while(p != NULL && q != NULL) {
        cout << "P: " << p->val << "; Q: " << q->val << endl;
        if(p->val != q->val) {
            return false;
        }
        p=p->next;
        q=q->next;
    }
    if(p == NULL && q == NULL) {
        return true;
    }
    else if(q == NULL) {
        return true;
    }
    else {
        return false;
    }
}
