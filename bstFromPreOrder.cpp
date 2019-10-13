TreeNode* constructTree(vector<int>& preorder, int& preIndex, int value, int min, int max) {

	if(preIndex >= preorder.size()) {
		return NULL;
	}

	TreeNode* root = NULL;

	if(value > min && value < max) {
		root = new TreeNode(value);
		preIndex++;

		if(preIndex < preorder.size()) {
			root->left = constructTree(preorder, preIndex, preorder[preIndex], min, value);
			root->right = constructTree(preorder, preIndex, preorder[preIndex], value, max);
		}
	}
	return root;

}

TreeNode* bstFromPreorder(vector<int>& preorder) {
	int preIndex = 0;
	return constructTree(preorder, preIndex, preorder[0], INT_MIN, INT_MAX);
}