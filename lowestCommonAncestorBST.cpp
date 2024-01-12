#include "TreeNode.h"

/*
  Since it is a BST, we want to find the split point.
  The split point is either (1) where p and q won't be part of the
  same subtree below this node or (2) one is the parent of the other.
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int pVal = p->val;
	int qVal = q->val;
	TreeNode* node = root;
	while(node != NULL) {
		int parentVal = node->val;
		if(pVal > parentVal && qVal > parentVal) {
			node = node->right;
		}
		else if(pVal < parentVal && qVal < parentVal) {
			node = node->left;
		}
		else {
			return node;
		}
	}
	return NULL;
}