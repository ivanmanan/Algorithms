#include "globals.h"


vector<vector<int>> levelOrder(TreeNode* root) {

	// Index: level, Value: array of nodes
	vector<vector<int>> res;
	if(root == NULL) {
		return res;
	}

	// BFS using a queue<node, level>
	queue<pair<TreeNode*, int>> q;
	q.push(make_pair(root, 1));

	while(!q.empty()) {

		pair<TreeNode*,int> m_pair = q.front();
		q.pop();

		TreeNode* curr = m_pair.first;
		int level = m_pair.second;

		if(level > res.size()) {
			vector<int> temp = {curr->val};
			res.push_back(temp);
		}
		else {
			// Exists in array already
			res[level-1].push_back(curr->val);
		}
		if(curr->left != NULL) {
			q.push(make_pair(curr->left, level+1));
		}
		if(curr->right != NULL) {
			q.push(make_pair(curr->right, level+1));
		}
	}


	return res;
}

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