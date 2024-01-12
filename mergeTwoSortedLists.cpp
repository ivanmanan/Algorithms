#include "globals.h"

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* p = list1;
    ListNode* q = list2;

    ListNode* head = NULL;
    ListNode* curr = NULL;

    while(p != NULL && q != NULL) {
        if(p->val <= q->val) {
            if(head == NULL) {
                head = p;
                curr = head;
            }
            else {
                curr->next = p;
                curr = curr->next;
            }
            p = p->next;
        }
        else {
            if(head == NULL) {
                head = q;
                curr = head;
            }
            else {
                curr->next = q;
                curr = curr->next;
            }
            q = q->next;
        }
    }
    if(p != NULL) {
        if(head == NULL) {
            return p;
        }
        else {
            curr->next = p;
        }
    }
    else if(q != NULL) {
        if(head == NULL) {
            return q;
        }
        else {
            curr->next = q;
        }
    }
    return head;

}
