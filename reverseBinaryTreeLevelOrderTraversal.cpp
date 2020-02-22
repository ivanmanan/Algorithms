#include "globals.h"

vector<vector<int>> levelOrderBottom(TreeNode* root) {

	vector<vector<int>> res;

	if(root == NULL) {
		return res;
	}

	queue<TreeNode*> currLevel;
	queue<TreeNode*> nextLevel;
	stack<queue<TreeNode*>> st;

	currLevel.push(root);
	st.push(currLevel);

	while(!currLevel.empty()) {

		TreeNode* node = currLevel.front();
		currLevel.pop();

		if(node->left != NULL) {
			nextLevel.push(node->left);
		}
		if(node->right != NULL) {
			nextLevel.push(node->right);
		}

		if(currLevel.empty() && !nextLevel.empty()) {
			st.push(nextLevel);
			swap(currLevel, nextLevel);
		}
	}

	while(!st.empty()) {
		vector<int> level;
		queue<TreeNode*> q = st.top();
		st.pop();

		while(!q.empty()) {
			int value = (q.front())->val;
			q.pop();
			level.push_back(value);
		}
		res.push_back(level);
	}
	return res;
}
