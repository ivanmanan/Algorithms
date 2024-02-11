Node* cloneGraph(Node* node) {
    if(node == NULL) {
        return node;
    }
    // old,new
    unordered_map<Node*,Node*> ma;

    Node* head = new Node(node->val);
    ma[node] = head;

    queue<Node*> q;
    q.push(node);

    while(!q.empty()) {
        Node* curr = q.front();
        Node* new_curr = ma[curr]; // Already exists in map for certain
        cout << curr->val << endl;
        q.pop();

        for(auto& child: curr->neighbors) {
            auto got = ma.find(child);
            if(got == ma.end()) {
                // Did not create node yet
                Node* new_child = new Node(child->val);
                q.push(child);
                new_curr->neighbors.push_back(new_child);
                ma[child] = new_child;
            }
            else {
                // Node already created
                new_curr->neighbors.push_back(got->second);
            }
        }
    }
    return head;
}
