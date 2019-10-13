vector<vector<int>> levelOrder(TreeNode* root) {

	vector<vector<int>> traversal;
	if(!root) {
		return traversal;
	}
	vector<int> level;

	queue<TreeNode*> currentLevel;
	queue<TreeNode*> nextLevel;

	currentLevel.push(root);

	while(!currentLevel.empty()) {

		TreeNode* node = currentLevel.front();
		currentLevel.pop();

		level.push_back(node->val);
		if(node->left != NULL) {
			nextLevel.push(node->left);
		}
		if(node->right != NULL) {
			nextLevel.push(node->right);
		}


		if(currentLevel.empty()) {
			traversal.push_back(level);
			level.clear();
			swap(currentLevel,nextLevel);
		}


	}
	return traversal;
}