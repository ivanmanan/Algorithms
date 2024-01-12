#include "globals.h"

Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* l1 = p;
    Node* l2 = q;

    while(l1 != l2) {
        if(l1 != NULL) {
            l1 = l1->parent;
        }
        else {
            l1 = q;
        }
        if(l2 != NULL) {
            l2 = l2->parent;
        }
        else {
            l2 = p;
        }
    }
    return l1;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> set;
    while(headB != NULL) {
        set.insert(headB);
        headB = headB->next;
    }
    while(headA != NULL) {
        auto got = set.find(headA);
        if(got != set.end()) {
            return headA;
        }
        headA = headA->next;
    }
    return NULL;
}
