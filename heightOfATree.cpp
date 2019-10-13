#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	TreeNode(int x) : val(x) {};
	int val;

	TreeNode* left;
	TreeNode* right;

	// For non-binary trees
	//vector<TreeNode*> children;
};

// Gives height of a binary tree
int findHeight(TreeNode* node) {

	// Base Case
	if (node == NULL) {
		return 0;
	}

	int L = findHeight(node->left) + 1;
	int R = findHeight(node->right) + 1;

	if (L > R) {
		return L;
	}
	else {
		return R;
	}
}

// DFS implementation
// Gives vector of order of DFS algorithm
void DFS(TreeNode* node, vector<int>& solution) {
	if (node == NULL) {
		return;
	}

	// Operate on current node first
	// Then go through left nodes first
	// Then go through right nodes
	solution.push_back(node->val);

	DFS(node->left, solution);
	DFS(node->right, solution);
}

void inOrderTraverse(TreeNode* node, vector<int>& solution) {

	if (node == NULL) {
		return;
	}

	// Left node first
	inOrderTraverse(node->left, solution);

	// Then current node
	solution.push_back(node->val);

	// Then right node
	inOrderTraverse(node->right, solution);
}


int main() {

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


	int height = findHeight(root);
	cout << "height: " << height << endl;

	vector<int> solution;
	//DFS(root, solution);
	inOrderTraverse(root, solution);
	for (auto it = solution.begin(); it != solution.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;


	delete root->right->left;
	delete root->right->right;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;
}