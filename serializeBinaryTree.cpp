// TODO: Complete the rest of this algorithm in Leetcode


// Encodes a tree to a single string.

// String format is the following:
// "preOrder + inOrder"
// where each word symbolizes "1 2 3 4 5 ..."
// and the "+" sign indicates the border

#include "TreeNode.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;



void traverseTree(TreeNode* root, vector<int>& preorder, vector<int>& inorder) {
	if(root == NULL) {
		return;
	}
	preorder.push_back(root->val);
	traverseTree(root->left, preorder, inorder);
	inorder.push_back(root->val);
	traverseTree(root->right, preorder, inorder);
}


vector<vector<int>> serialize(TreeNode* root) {

	vector<int> preorder;
	vector<int> inorder;

	// Fill-in the traversal vectors
	traverseTree(root, preorder, inorder);

	vector<vector<int>> data;
	data.push_back(preorder);
	data.push_back(inorder);
	return data;
}

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


// Decodes your encoded data to tree.
TreeNode* deserialize(vector<vector<int>> preorderInorder) {

	vector<int> preorder = preorderInorder[0];
	vector<int> inorder = preorderInorder[1];

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