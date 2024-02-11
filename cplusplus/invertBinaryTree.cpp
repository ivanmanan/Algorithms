#include "globals.h"

TreeNode* invertTree(TreeNode* root) {

	if(root == NULL) {
		return NULL;
	}

	root->left = invertTree(root->left);
	root->right = invertTree(root->right);

	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	return root;
}