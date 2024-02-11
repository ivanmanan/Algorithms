#include "globals.h"

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

	vector<vector<int>> zigzag;

	if(!root) {
		return zigzag;
	}

	stack<TreeNode*> currentLevel;
	stack<TreeNode*> nextLevel;

	bool leftToRight = true;

	currentLevel.push(root);

	vector<int> level;

	while(!currentLevel.empty()) {
		TreeNode* node = currentLevel.top();
		currentLevel.pop();

		if(node) {
			level.push_back(node->val);
			if(leftToRight) {
				if(node->left != NULL) {
					nextLevel.push(node->left);
				}
				if(node->right != NULL) {
					nextLevel.push(node->right);
				}

			}
			else {
				if(node->right != NULL) {
					nextLevel.push(node->right);
				}
				if(node->left != NULL) {
					nextLevel.push(node->left);
				}
			}
		}

		if(currentLevel.empty()) {
			zigzag.push_back(level);
			level.clear();
			leftToRight = !leftToRight;
			swap(currentLevel, nextLevel);
		}

	}

	return zigzag;
}