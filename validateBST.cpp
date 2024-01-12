#include "globals.h"


bool inorder(TreeNode* root, long int left, long int right) {
    if(root == NULL) return true;
    // Do current node
    if(root->val > left && root->val < right) {
        bool l = inorder(root->left, left, root->val);
        bool r = inorder(root->right, root->val, right);
        return l && r;
    }
    return false;
}


bool isValidBST(TreeNode* root) {
    return inorder(root, LONG_MIN, LONG_MAX);
}