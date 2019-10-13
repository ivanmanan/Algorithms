#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

void DFS(TreeNode* node, vector<int>& solution) {

	if (node == NULL) {
		return;
	}

	for (auto it = node->children.begin(); it != node->children.end(); it++) {
		DFS(*it, solution);
	}

	solution.push_back(node->value);
}

int main() {

	// TODO: Create C++ header file for non-binary tree
	TreeNode* root = new TreeNode();
}