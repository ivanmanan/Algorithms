/*
    N nodes
    Height of binary tree O(N); balanced tree is O(log N)

    Sorting keys can be O(N log N) if each parent node only has one child node
*/
vector<vector<int>> verticalOrder(TreeNode* root) {

    map<int,vector<int>> ma;
    vector<vector<int>> res;
    if(root == NULL) {
        return res;
    }

    // Do BFS for top-to-bottom
    queue<pair<TreeNode*,int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        TreeNode* curr = q.front().first;
        int col = q.front().second;
        q.pop();

        auto got = ma.find(col);
        if(got != ma.end()) {
            // Exists in map
            ma[col].push_back(curr->val);
        }
        else {
            ma[col] = {curr->val};
        }

        if(curr->left != NULL) {
            q.push(make_pair(curr->left,col-1));
        }
        if(curr->right != NULL) {
            q.push(make_pair(curr->right,col+1));
        }

    }

    for(auto& it: ma) {
        res.push_back(it.second);
    }
    return res;
}

// Same solution but avoid sorting keys
vector<vector<int>> verticalOrder(TreeNode* root) {
    if(root == NULL) {
        return vector<vector<int>>();
    }
    // Key: col, value: vector
    unordered_map<int,vector<int>> ma;

    // Used to avoid sorting keys
    int lowest_col = 0;

    // Node, col number
    queue<pair<TreeNode*,int>> q;

    q.push({root, lowest_col});

    while(!q.empty()) {
        TreeNode* curr = q.front().first;
        int col = q.front().second;
        q.pop();

        ma[col].push_back(curr->val);

        if(curr->left != NULL) {
            q.push({curr->left, col-1});
        }
        if(curr->right != NULL) {
            q.push({curr->right, col+1});
        }
        lowest_col = min(lowest_col, col);
    }
    // Number of columns in ma - initialize as vector
    vector<vector<int>> res(ma.size());
    int diff = 0;
    if(lowest_col < 0) {
        diff = abs(lowest_col); // indexes must be positive
    }
    for(int i = lowest_col; ma.find(i) != ma.end(); i++) {
        res[i+diff] = ma[i];
    }
    return res;
}
