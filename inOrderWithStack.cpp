#include "TreeNode.h"
#include <stack>

vector<TreeNode*> inOrderWithStack(TreeNode* root) {

	vector<TreeNode*> traversal;

	// In-order is L C R
	stack<TreeNode*> s;
	TreeNode* curr = root;


	while(curr != NULL || !s.empty()) {


		// Reach the left most node accessible by the current node
		while(curr != NULL) {

			s.push(curr);
			curr = curr->left;
		}

		// Current pointer must be NULL at this point
		curr = s.top();
		s.pop();

		traversal.push_back(curr);

		// We have visited the node and its left subtree
		// Time to visit right subtree
		curr = curr->right;
	}
	return traversal;
}

int main() {
	TreeNode* root = createBST();
	vector<TreeNode*> ans = inOrderWithStack(root);

	for(auto it = ans.begin(); it != ans.end(); it++) {
		cout << (*it)->val << endl;
	}
	deleteTree(root);
}