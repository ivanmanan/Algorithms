#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

vector<int> BFS(TreeNode* root) {
	vector<int> solution;

	queue<TreeNode*> queue;

	queue.push(root);

	while (!queue.empty()) {

		TreeNode* r = queue.front();
		solution.push_back(r->val);
		queue.pop();

		if (r->left != NULL) {
			queue.push(r->left);
		}
		if (r->right != NULL) {
			queue.push(r->right);
		}
	}

	return solution;
}

int main() {
	TreeNode* root = createTree();

	vector<int> ans = BFS(root);

	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << " " << endl;

	}
	deleteTree(root);
}
