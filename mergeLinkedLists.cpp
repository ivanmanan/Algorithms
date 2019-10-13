// Assume both linked lists are sorted

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* solution;

        // Create root node
        if (p1 == NULL || p2 == NULL) {
            if (p1 == NULL && p2 != NULL) {
                solution = new ListNode(p2->val);
            }
            else if (p1 != NULL && p2 == NULL) {
                solution = new ListNode(p1->val);
            } // Both are nulls
            else {
                solution = NULL;
                return solution;
            }
        }
        else if (p1->val > p2->val) {
            solution = new ListNode(p2->val);
            p2 = p2->next;
        }
        else {
            solution = new ListNode(p1->val);
            p1 = p1->next;
        }

        // Point to beginning of linked list
        ListNode* ans = solution;

        while (p1 != NULL || p2 != NULL) {

            // p1 is null, then append p2 to linked list
            if (p1 == NULL) {
                solution->next = p2->next;
                solution = solution->next;
                p2 = p2->next;
            } // vice versa
            else if (p2 == NULL) {
                solution->next = p1->next;
                solution = solution->next;
                p1 = p1->next;
            }
            // Compare which is smaller
            else if (p1->val > p2->val) {
                solution->next = new ListNode(p2->val);
                solution = solution->next;
                p2 = p2->next;
            }
            else {
                solution->next = new ListNode(p1->val);
                solution = solution->next;
                p1 = p1->next;
            }
        }

        return ans;
    }
};