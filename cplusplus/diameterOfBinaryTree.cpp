int dfs(TreeNode* root, int& res) {
    if(root == NULL) {
        return 0;
    }
    int l = dfs(root->left, res);
    int r = dfs(root->right, res);
    int diam_candidate = l + r;
    res = max(res, diam_candidate);
    return max(l,r)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res;
}
