#include "TreeNode.h"

TreeNode* LCA = NULL;

bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root == NULL) {
		return false;
	}

	bool L = dfs(root->left, p, q);
	bool R = dfs(root->right, p, q);

	// if current node is either p or q
	bool mid = (root == p || root == q);

	// check if any two flags become true
	/*
	  1. (L && R) --> backtrack to where L and R are both true
	  2. (mid && L) --> this means target node is LCA
	  3. (mid && R) --> this means target node is LCA
	 */
	if((mid && L) || (mid && R) || (L && R)) {
		LCA = root;
	}
	return (mid || L || R);
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	dfs(root, p, q);
	return LCA;
}