#include "globals.h"

// If the graph is not a tree, then you must tag the node that it has been
// visited so you can avoid infinite loops caused by cycles
// If the graph is not a binary tree, then you iterate every child node

vector<int> BFS(TreeNode* root) {

	vector<int> res;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {

		TreeNode* node = q.front();
		q.pop();
		res.push_back(node->val);

		if(node->left != NULL) {
			q.push(node->left);
		}
		if(node->right != NULL) {
			q.push(node->right);
		}
	}
	return res;
}

int main() {
	TreeNode* root = createTree();

	vector<int> ans = BFS(root);

	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << " " << endl;

	}
	deleteTree(root);
}
