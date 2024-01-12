int maxLevelSum(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    // node, level
    queue<pair<TreeNode*,int>> q;
    q.push({root, 1});

    int curr_level = 0;
    int level_sum = INT_MIN;
    int res = 0;
    int res_sum = INT_MIN;
    while(!q.empty()) {
        TreeNode* curr = q.front().first;
        int level = q.front().second;
        q.pop();

        if(curr_level == level) {
            level_sum += curr->val;
        }
        else {
            // Compare as candidate since we got the entire level's sum
            if(level_sum > res_sum) {
                res_sum = level_sum;
                res = curr_level;
            }
            level_sum = curr->val;
            curr_level = level;
        }

        if(curr->left != NULL) {
            q.push({curr->left, level+1});
        }
        if(curr->right != NULL) {
            q.push({curr->right, level+1});
        }
    }
    // Compare last level!
    if(level_sum > res_sum) {
        res = curr_level;
    }
    return res;
}
