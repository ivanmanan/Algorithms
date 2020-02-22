#include "globals.h"

vector<vector<int>> levelOrder(TreeNode* root) {

	vector<vector<int>> res;
	vector<int> level;

	queue<TreeNode*> currLevel;
	queue<TreeNode*> nextLevel;

	currLevel.push(root);

	while(!currLevel.empty()) {

		TreeNode* node = currLevel.front();
		currLevel.pop();
		level.push_back(node->val);

		if(node->left != NULL) {
			nextLevel.push(node->left);
		}
		if(node->right != NULL) {
			nextLevel.push(node->right);
		}

		if(currLevel.empty()) {
			res.push_back(level);
			level.clear();
			swap(currLevel, nextLevel);
		}
	}
	return res;
}


int main() {
	TreeNode* root = createTree();
	vector<vector<int>> res = levelOrder(root);

	for(auto it = res.begin(); it != res.end(); it++) {
		for(auto ite = it->begin(); ite != it->end(); ite++) {
			cout << *ite << endl;
		}
	}
	deleteTree(root);
}