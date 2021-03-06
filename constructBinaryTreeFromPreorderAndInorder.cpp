/*
  1. Start with the root node - the first item in the preorder
  traversal.
  2. The index of the preorder value in the inorder traversal
  corresponds to the inflection point - everything left of the
  inflection point is the left subtree and everything right of the
  inflection point is the right subtree.
  3. Recurse this process. Have a conditional statement to indicate
  when the recursive function reaches a leaf node.


  preorder = [3,9,20,15,7]
  inorder  = [9,3,15,20,7]

           3
		  /  \
		 9   20
            /  \
		   15  7

  WALKTHROUGH
  0. buildTree(start, end, preIndex)
  1. buildTree(0, 4, 0)
       root->left  = buildTree(0, 0, 1)
       root->right = buildTree(2, 4, 2)
*/

#include "globals.h"

TreeNode* buildTree(const vector<int>& preorder, int start, int end, int& preIndex,unordered_map<int,int>& ma) {

	// Out of bounds to indicate previous node was a leaf node
	if(start > end) {
		return NULL;
	}

	// Create root of subtree
	int currValue = preorder[preIndex++];
	TreeNode* root = new TreeNode(currValue);

	// Find inorder index of this node
	int inIndex = ma[currValue];

	// Create left subtree
	root->left = buildTree(preorder, start, inIndex-1, preIndex, ma);

	// Create right subtree
	root->right = buildTree(preorder, inIndex+1, end, preIndex, ma);
	return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	// Build hash table for inorder vector to map node value to index
	// NOTE: This method does not work if duplicates exist
	unordered_map<int,int> ma;
	for(uint i = 0; i < inorder.size(); i++) {
		ma[inorder[i]] = i;
	}
	int preIndex = 0;
	TreeNode* root = buildTree(preorder, 0, inorder.size()-1, preIndex, ma);
	return root;
}