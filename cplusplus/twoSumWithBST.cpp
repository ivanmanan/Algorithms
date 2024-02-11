#include "globals.h"

void dfs(TreeNode* root, vector<int>& sorted) {

	if(root == NULL) {
		return;
	}

	// In-order traversal is L C R
	dfs(root->left, sorted);
	sorted.push_back(root->val);
	dfs(root->right, sorted);
}

bool findTarget(TreeNode* root, int k) {
	// Place elements into sorted array
	vector<int> sorted;
	dfs(root, sorted);

	// Two pointers method
	for(int l = 0, r = sorted.size()-1; l < r;) {
		int sum = sorted[l] + sorted[r];
		if(sum == k) {
			return true;
		}
		else if(sum < k) {
			l++;
		}
		else {
			r--;
		}
	}
	return false;
}