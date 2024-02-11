#include "globals.h"



int dfs(TreeNode* root, bool& res) {
	if(root == NULL) {
		return 0;
	}

	int l = dfs(root->left, res) + 1;
	int r = dfs(root->right, res) + 1;

	if(abs(l-r) > 1) {
		res = false;
		return -1; // End immediately
	}
	return max(l, r);
}

bool isBalanced(TreeNode* root) {
	bool res = true;
	dfs(root, res);
	return res;
}


int height(TreeNode* root, int currDepth, bool& res) {
	if(root == NULL) {
		return currDepth;
	}

	int L = height(root->left, currDepth+1, res);
	int R = height(root->right, currDepth+1, res);

	if(abs(L - R) > 1) {
		res = false;
	}
	return max(L,R);
}

bool isBalanced(TreeNode* root) {
	bool res = true;
	height(root, 0, res);
	return res;
}