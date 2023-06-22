// Path Sum I
bool hasPathSum(TreeNode* root, int targetSum) {
	if(root == NULL) {
		return false;
	}
	if(root->val == targetSum && !root->left && !root->right) {
		return true;
	}
	return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
}

// Path Sum II
void dfs(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int> path, int sum) {

	if(root == NULL) {
		return;
	}

	path.push_back(root->val);
	int curr_sum = root->val + sum;

	if(root->left == NULL && root->right == NULL) {
		// Reached terminal leaf
		if(curr_sum == targetSum) {
			res.push_back(path);
		}
	}
	else {
		dfs(root->left, targetSum, res, path, curr_sum);
		dfs(root->right, targetSum, res, path, curr_sum);
	}
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	vector<vector<int>> res;
	vector<int> path;
	int sum = 0;
	dfs(root, targetSum, res, path, sum);
	return res;
}

// Path Sum III
void dfs(TreeNode* root, int& targetSum, int& res, vector<int>& seen, int partialSum) {

	partialSum += root->val;

	for(auto it = seen.begin(); it != seen.end(); it++) {
		// Check if we found an interval reaching the sum
		cout << *it << " == " << partialSum << " - " << targetSum << endl;
		// partialSum = 18 (10 + 5 + 3)
		// *it = 10 (root node value)
		// targetSum = 8
		// 18 - 10 == 8
		if(partialSum - *it == targetSum) {
			cout << "HIT" << endl;
			res++;
		}
	}
	seen.push_back(partialSum);
	if(root->left != NULL) {
		dfs(root->left, targetSum, res, seen, partialSum);
	}
	if(root->right != NULL) {
		dfs(root->right, targetSum, res, seen, partialSum);
	}
	// Clear the seen one level, for backtracking purposes
	seen.pop_back();
}

int pathSum(TreeNode* root, int targetSum) {
	int res = 0;
	vector<int> seen = {0};
	if(root == NULL) {
		return res;
	}
	dfs(root, targetSum, res, seen, 0);
	return res;
}
