#include "globals.h"

bool isBSTwithStack(TreeNode* root) {

	if(root == NULL) {
		return true;
	}

	// Do inOrder traversal - L C R
	TreeNode* curr = root;
	stack<TreeNode*> st;

	int prev = - INT_MAX;

	while(curr != NULL || !st.empty()) {

		while(curr != NULL) {
			st.push(curr);
			curr = curr->left;
		}

		// Prev node corresponds to the order of in-order traversal
		curr = st.top();
		st.pop();

		if(prev >= curr->val) {
			return false;
		}
		prev = curr->val;
		curr = curr->right;

	}
	return true;
}

// Do in-order traversal
bool isBST(TreeNode* root, TreeNode* prev) {

	if (root == NULL) {
		return true;
	}

	// Go left node first
	if (!isBST(root->left, prev)) {
		return false;
	}

	// Do current node
	if (prev != NULL && prev->val >= root->val) {
		return false;
	}

	// Do right node
	return isBST(root->right, root);
}

int main() {
	TreeNode* root = createBST();

	bool ans = isBSTwithStack(root);

	cout << "Expected Answer: True" << endl;
	if(ans) {
		cout << "Real Answer: True" << endl;
	}
	else {
		cout << "Real Answer: False" << endl;
	}

	deleteTree(root);
}

