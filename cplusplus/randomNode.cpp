#include "globals.h"

/*
  Store tree in inorder traversal
  Select random index from the array
 */

void dfs(TreeNode* root, vector<int>& traversal) {
	if(root == NULL) {
		return;
	}
	dfs(root->left, traversal);
	traversal.push_back(root->val);
	dfs(root->right, traversal);
}

int randomNode(TreeNode* root) {
	vector<int> traversal;
	dfs(root, traversal);

	// Select random index from array
	int r = rand() % (traversal.size());
	return traversal[r];
}

int main() {
	TreeNode* root = createTree();
	srand (time(0));
	int res = randomNode(root);
	cout << "Output: " << res << endl;
	deleteTree(root);
}