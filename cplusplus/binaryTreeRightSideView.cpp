#include "globals.h"

void dfs(TreeNode* root, int depth, vector<int>& res) {

	if(root == NULL) {
		return;
	}

	if(depth == res.size()) {
		res.push_back(root->val);
	}
	dfs(root->right, depth+1, res);
	dfs(root->left, depth+1, res);
}

vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	int depth = 0;
	dfs(root, depth, res);
	return res;
}







void dfs(TreeNode* root, int currDepth, vector<int>& res) {

	if(root == NULL) {
		return;
	}

	if(currDepth > res.size()) {
		res.push_back(root->val);
	}

	dfs(root->right, currDepth+1, res);
	dfs(root->left, currDepth+1, res);

}

vector<int> rightSideView(TreeNode* root) {
	vector<int> res;

	if(root == NULL) {
		return res;
	}

	dfs(root, 1, res);
	return res;
}