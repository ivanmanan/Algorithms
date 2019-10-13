#include <iostream>

using namespace std;

/*
  Reverse inOrder traversal

  inOrder - L N R
  Reverse inOrder - R N L
 */

void reverseInOrder(TreeNode* root, int& sum) {
	if(root == NULL) {
		return;
	}
	reverseInOrder(root->right, sum);

	sum += root->val;
	root->val = sum;

	reverseInOrder(root->left, sum);
}

TreeNode* bstToGst(TreeNode* root) {

	int sum = 0;
	reverseInOrder(root, sum);

	return root;
}