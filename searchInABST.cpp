#include "globals.h"

TreeNode* searchBST(TreeNode* root, int val) {

	if(root != NULL && root->val == val) {
		return root;
	}
	else if(root != NULL && root->val > val) {
		return searchBST(root->left, val);
	}
	else if(root != NULL && root->val < val) {
		return searchBST(root->right, val);
	}
	else {
		return NULL;
	}

}