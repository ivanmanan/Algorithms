#include "globals.h"

bool dfs(TreeNode* s, TreeNode* t) {

	if(s == NULL && t == NULL) {
		return true;
	}
	else if(s == NULL || t == NULL) {
		return false;
	}
	if(s->val == t->val) {
		bool L = dfs(s->right, t->left);
		bool R = dfs(s->left, t->right);
		return L && R;
	}
	else {
		return false;
	}
}

bool isSymmetric(TreeNode* root) {

	if(root == NULL) {
		return true;
	}

	return dfs(root->left, root->right);
}