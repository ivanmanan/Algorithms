// Compile this cod ehere


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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;

        // Iterate through linked list
        for (; temp != NULL; temp = temp->next) {

            // Remove that node and update linked list accordingly
            if (temp->val == val) {

                // Check if tail pointer contains that value
                if (temp->next == NULL) {
                    delete temp->next;
                    temp = NULL;
                    break;
                }
                else {
                    temp->val = temp->next->val;
                    temp->next = temp->next->next;
                }
            }
        }
        return head;
    }
};