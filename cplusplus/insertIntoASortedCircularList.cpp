/*

head -> 1 -> 3 -> 5 -> 7 -> 8 -> 9 -> head
Say that 3 is the entrance.

CASE 1: new node is between min and max values.
Insert 6: prev=5, curr=7.

CASE 2: new node is less than minimal
or greater than maximal
Insert 10: prev=9, curr=1
Insert 0: prev=9, curr=1

CASE 3: entire list is uniform
3 -> 3 -> 3 -> 3
Insert 10: anywhere after the head pointer

TIME: O(N)
SPACE: O(1)
*/

Node* insert(Node* head, int insertVal) {
    if(head == NULL) {
        head = new Node(insertVal);
        head->next = head;
        return head;
    }

    Node* prev = head;
    Node* curr = head->next;
    bool insert = false;
    do { // Condition is checked after loop body is executed
        if(prev->val <= insertVal && insertVal < curr->val) {
            insert = true; // Case 1
        }
        else if(prev->val > curr->val) {
            // 1 -> 3 -> 5 -> 7 -> 8 -> 9 -> ...
            // If we want to insert 0 or 10,
            // prev=9,curr=1
            if(insertVal >= prev->val || insertVal <= curr->val) {
                insert = true;
            }
        }
        if(insert) {
            Node* temp = new Node(insertVal);
            prev->next = temp;
            temp->next = curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while(prev != head);
    // 3 -> 3 -> 3 -> 3
    // Handle case if all elements are uniform
    Node* temp = new Node(insertVal);
    prev->next = temp;
    temp->next = curr;
    return head;
}
