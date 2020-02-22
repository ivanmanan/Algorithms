#include "globals.h"

vector<int> inorderTraversalWithStack(TreeNode* root) {
	vector<int> res;
	TreeNode* curr = root;
	stack<TreeNode*> st;

	while(curr != NULL || !st.empty()) {

		// Go leftmost node
		while(curr != NULL) {
			st.push(curr);
			curr = curr->left;
		}

		// Curr is empty, so go to top of stack
		curr = st.top();
		st.pop();
		res.push_back(curr->val);

		// Go to right node
		curr = curr->right;
	}
	return res;
}


void traverseTree(TreeNode* node, vector<int>& order) {
	if (node == NULL)
		return;

	traverseTree(node->left, order);
	order.push_back(node->val);
	traverseTree(node->right, order);
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> order;
	this->traverseTree(root, order);
	return order;
}
