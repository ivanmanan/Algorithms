/*
    Output should be in preorder: P L R
    Process via postorder: P L R
*/
TreeNode* dfs(TreeNode* root) {
    if(root == NULL) {
        return NULL;
    }

    TreeNode* leftchild = dfs(root->left);
    TreeNode* rightchild = dfs(root->right);

    if(leftchild != NULL) {
        root->left = NULL;
        root->right = leftchild;
        while(leftchild != NULL && leftchild->right != NULL) {
            // Iterate to end of list of leftchildren
            leftchild = leftchild->right;
        }
        leftchild->right = rightchild;
    }

    return root;
}

void flatten(TreeNode* root) {
    dfs(root);
}
