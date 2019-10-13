#include <iostream>
#include <queue>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
	TreeNode(int x) : val(x) {};
	int val;

	TreeNode* left;
	TreeNode* right;

	// For non-binary trees
	//vector<TreeNode*> children;
};

TreeNode* createTree();

// N = node, L = left, R = right

// N L R
void preOrderTraverse(TreeNode* root, vector<int>& solution) {
	if (root == NULL) {
		return;
	}
	solution.push_back(root->val);
	preOrderTraverse(root->left, solution);
	preOrderTraverse(root->right, solution);
}

// L N R
void inOrderTraverse(TreeNode* root, vector<int>& solution) {
	if (root == NULL) {
		return;
	}
	inOrderTraverse(root->left, solution);
	solution.push_back(root->val);
	inOrderTraverse(root->right, solution);
}

// L R N
void postOrderTraverse(TreeNode* root, vector<int>& solution) {
	if (root == NULL) {
		return;
	}
	postOrderTraverse(root->left, solution);
	postOrderTraverse(root->right, solution);
	solution.push_back(root->val);
}


int main() {
	TreeNode* root = createTree();

	vector<int> ans;
	postOrderTraverse(root, ans);

	// See if this gets overwrite
	// preOrderTraverse(root, ans);

	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;



	delete root->right->left;
	delete root->right->right;
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;
}

TreeNode* createTree() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	root->left->left->right = NULL;
	root->left->right->right = NULL;
	root->right->left->right = NULL;
	root->right->right->right = NULL;
	root->left->left->left = NULL;
	root->left->right->left = NULL;
	root->right->left->left = NULL;
	root->right->right->left = NULL;

	return root;
}