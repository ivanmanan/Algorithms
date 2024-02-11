void inOrderTraversal(TreeNode* root, int L, int R, int& sum) {
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root->left, L, R, sum);

    if(root->val >= L && root->val <= R) {
        sum += root->val;
    }

    inOrderTraversal(root->right, L, R, sum);
}


int rangeSumBST(TreeNode* root, int L, int R) {
    int sum = 0;
    inOrderTraversal(root, L, R, sum);
    return sum;
}
