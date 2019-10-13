/*
  Same as binary level traversal except it's reading from
  bottom to top.

  Basically backwards BFS.
*/

#include <vector>
#include "TreeNode.h"
#include <queue>
#include <stack>

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> reverseTraversal;
	if(!root) {
		return reverseTraversal;
	}

	queue<TreeNode*> currentLevel;
	queue<TreeNode*> nextLevel;
	stack<queue<TreeNode*>> s;


	currentLevel.push(root);
	s.push(currentLevel);

	while(!currentLevel.empty()) {

		TreeNode* node = currentLevel.front();
		currentLevel.pop();

		if(node->left != NULL) {
			nextLevel.push(node->left);
		}
		if(node->right != NULL) {
			nextLevel.push(node->right);
		}

		if(currentLevel.empty()) {
			s.push(nextLevel);
			swap(currentLevel, nextLevel);
		}

	}

	while(!s.empty()) {
		vector<int> level;
		queue<TreeNode*> q = s.top();

		while(!q.empty()) {

			int value = (q.front())->val;
			q.pop();
			level.push_back(value);
		}
		reverseTraversal.push_back(level);
	}
	return reverseTraversal;

}
