// Create a hash table mapping old node to new node
// 1st pass: handle next pointers while inserting into the map
// 2nd pass: handle random pointers
Node* copyRandomList(Node* head) {
    Node* new_head = NULL;
    if(head != NULL) {
        new_head = new Node(head->val);
    }
    else {
        return new_head;
    }
    Node* curr = head;
    curr = curr->next;
    Node* new_curr = new_head;

    // Key: old_node, value: new_node
    unordered_map<Node*, Node*> ma;
    ma[head] = new_head;

    // Create new nodes
    while(curr != NULL) {
        Node* new_node = new Node(curr->val);
        new_curr->next = new_node;
        ma[curr] = new_node;
        curr = curr->next;
        new_curr = new_curr->next;
    }
    Node* tail = new_curr;

    // Copy random pointers
    curr = head;
    new_curr = new_head;
    while(curr != NULL) {
        if(curr->random != NULL) {
            new_curr->random = ma[curr->random];
        }
        else {
            new_curr->random = NULL;
        }
        curr = curr->next;
        new_curr = new_curr->next;
    }

    return new_head;
}
