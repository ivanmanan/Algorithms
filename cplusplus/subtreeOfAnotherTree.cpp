#include "globals.h"

bool dfs(TreeNode* t, TreeNode* s) {
	if(s == NULL && t == NULL) {
		return true;
	}
	if(s == NULL || t == NULL) {
		return false;
	}
	return (s->val == t->val && dfs(s->left, t->left) && dfs(s->right, t->right));
}

bool isSubtree(TreeNode* t, TreeNode* s) {

	// Subtree is NULL
	if(s == NULL) {
		return true;
	}

	if(t == NULL) {
		return false;
	}

	if(s->val == t->val) {
		if(dfs(t,s)) {
			return true;
		}
	}
	return (isSubtree(t->left, s) || isSubtree(t->right, s));
}