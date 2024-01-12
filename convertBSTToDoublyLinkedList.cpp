class ConvertBSTToDoublyLinkedList {
public:
    void dfs(Node* root) {
        if(root == NULL) {
            return;
        }
        // Go far left first
        dfs(root->left);

        if(head == NULL) {
            // bottom left element is smallest in BST
            head = root;
        }
        else {
            last->right = root; // link previous node (last)
            root->left = last;  // with current node (root)
        }
        last = root;
        dfs(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if(root == NULL) {
            return NULL;
        }
        dfs(root);
        // Close the doubly linked list
        last->right = head;
        head->left = last;

        return head;
    }
private:
    Node* head = NULL;
    Node* last = NULL;
};
