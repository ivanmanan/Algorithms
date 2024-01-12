/*
    Q: [1]
    Q: [2,3]
    Q: [4,5,6, NULL]
    nullFound
    --> if 4,5,6 nodes contain non-NULLs, then we return false

    Q: [1]
    Q: [2,3]
    Q: [4,5,NULL]
    nullFound
    7 is non-null, so return false
*/
bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    bool nullFound = false;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if(curr->left != NULL) {
            if(nullFound) {
                return false;
            }
            q.push(curr->left);
        }
        else {
            nullFound = true;
        }
        if(curr->right != NULL) {
            if(nullFound) {
                return false;
            }
            q.push(curr->right);
        }
        else {
            nullFound = true;
        }
    }
    return true;
}
