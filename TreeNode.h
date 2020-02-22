#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

struct TreeNode {
 public:
    TreeNode(int x) : val(x) {};
	int val;
	TreeNode* left;
	TreeNode* right;

	// For non-binary trees
	//vector<TreeNode*> children;
};

TreeNode* createTree() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	root->left->left->right = NULL;
	root->left->right->right = NULL;
	root->right->left->right = NULL;
	root->right->right->right = NULL;
	root->left->left->left = NULL;
	root->left->right->left = NULL;
	root->right->left->left = NULL;
	root->right->right->left = NULL;

	return root;
}

TreeNode* createBST() {
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	root->left->left->right = NULL;
	root->left->right->right = NULL;
	root->right->left->right = NULL;
	root->right->right->right = NULL;
	root->left->left->left = NULL;
	root->left->right->left = NULL;
	root->right->left->left = NULL;
	root->right->right->left = NULL;

	return root;
}

void deleteTree(TreeNode* root) {
	delete root->right->left;
	delete root->right->right;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;
}

#endif
