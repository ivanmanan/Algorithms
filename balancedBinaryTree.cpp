#include "globals.h"

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