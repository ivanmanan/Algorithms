#include "globals.h"

/*
  TODO: Need to fix this
 */

vector<list<int>> flatten(TreeNode* root) {

	vector<list<int>> res;

	// Node:Depth
	queue<pair<TreeNode*,int>> q;
	int currDepth = 1;
	q.push(make_pair(root, currDepth));

	list<int> dq;

	while(!q.empty()) {
		TreeNode* node = q.front().first;
		q.pop();
		int depth = q.front().second;

		if(currDepth != depth) {
			res.push_back(dq);
			dq.clear();
		}
		dq.push_back(node->val);

		if(node->left != NULL) {
			q.push(make_pair(node->left, depth+1));
		}
		if(node->right != NULL) {
			q.push(make_pair(node->right, depth+1));
		}
	}



	return res;
}

int main() {
	TreeNode* root = createTree();
	vector<list<int>> res = flatten(root);

	for(int i = 0; i < res.size(); i++) {
		for(auto it = res[i].begin(); it != res[i].end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	deleteTree(root);
}