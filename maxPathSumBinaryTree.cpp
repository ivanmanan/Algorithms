int maxPathSum(TreeNode* root) {
	int result = INT_MIN;
	dfs(root, result);
	return result;
}

/*
  Conditions to consider:
  1. Root only - children nodes are negative values
  2. Root + L
  3. Root + R
  4. Root + L + R
 */

int dfs(TreeNode *root, int &res) {
	if(root == NULL) {
		return 0;
	}

	int L = dfs(root->left, res);
	int R = dfs(root->right, res);

	// Max path for parent node with one child node
	int single_max = max(root->val, max(L,R) + root->val);

	// Max path when parent node under consideration is the root of the path
	int max_top = max(single_max, root->val + L + R);

	res = max(res, max_top);

	return single_max;
}

/*
  TREE VISUALIZATION

       2   --> returns 4
	 /
   -1      --> returns -1+3
   /
  3        --> returns 3

 */
