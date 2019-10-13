#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;


TreeNode* createTree();

// Keep track of depth
void preOrder(TreeNode* node, uint depth, vector<int>& view) {

	if (node == NULL) {
		return;
	}

	if (view.size() < depth) {
		view.push_back(node->val);
	}
	++depth;
	preOrder(node->left, depth, view);
	preOrder(node->right, depth, view);
}

vector<int> leftMostNodes(TreeNode* root) {
	vector<int> solution;
	preOrder(root, 1, solution);
	return solution;
}

int main() {
	TreeNode* root = createTree();

	vector<int> ans = leftMostNodes(root);

	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;

	}
}

