#include "globals.h"

void dfs(TreeNode* root, int currDepth, int& res) {
	if(root == NULL) {
		return;
	}

	dfs(root->left, currDepth+1, res);
	dfs(root->right, currDepth+1, res);

	if(root->left == NULL && root->right == NULL) {
		res = min(res,currDepth);
	}
}

int minDepth(TreeNode* root) {
	if(root == NULL) {
		return 0;
	}

	int res = INT_MAX;
	dfs(root, 1, res);
	return res;
}