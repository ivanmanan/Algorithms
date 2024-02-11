/*
    1. Compare root node to target
    2. If target < root, go left
        If target > root, go right
    3. Compare between root value and child value
    4. Return closest
*/
int closestValue(TreeNode* root, double target) {
    if(root == NULL) {
        return INT_MAX;
    }
    if(target == root->val) {
        return root->val;
    }
    TreeNode* child = root->right; // Go right
    if(target < root->val) {
        // Go left
        child = root->left;
    }
    int child_value = closestValue(child, target);
    double parent_distance = abs(root->val-target);
    double child_distance = abs(child_value-target);

    if(child_distance == parent_distance) {
        return min(root->val, child_value);
    }

    if(child_distance < parent_distance) {
        return child_value;
    }
    return root->val;
}
