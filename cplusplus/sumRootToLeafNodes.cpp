int sumNumbers(TreeNode* root) {
    // treenode, value
    queue<pair<TreeNode*,int>> q;
    q.push(make_pair(root, root->val));
    int res = 0;
    while(!q.empty()) {
        TreeNode* curr = q.front().first;
        int val = q.front().second;
        cout << "NODE: " << curr->val << "; VALUE: " << val << endl;
        q.pop();

        if(curr->left == NULL && curr->right == NULL) {
            // Leaf node - no children
            res += val;
        }
        if(curr->left != NULL) {
            int new_digit = curr->left->val;
            int new_val = val * 10 + new_digit;
            q.push(make_pair(curr->left,new_val));
        }
        if(curr->right != NULL) {
            int new_digit = curr->right->val;
            int new_val = val * 10 + new_digit;
            q.push(make_pair(curr->right,new_val));
        }
    }
    return res;
}
