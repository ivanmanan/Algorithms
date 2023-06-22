void dfs(TreeNode* p, TreeNode* q, bool& same) {
    if(p == NULL && q == NULL) {
        return;
    }
    else if(p == NULL) {
        same = false;
        return;
    }
    else if(q == NULL) {
        same = false;
        return;
    }
    else if(p->val != q->val) {
        same = false;
        return;
    }
    else {
        dfs(p->left, q->left, same);
        dfs(p->right, q->right, same);
    }
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    bool same = true;
    dfs(p, q, same);
    return same;
}
