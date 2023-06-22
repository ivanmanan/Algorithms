#include "globals.h"

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

	// Max path when current node is not the parent node
	// i.e. this is part of an existing path
	int single_max = max(root->val, max(L,R) + root->val);

	// Max path when the current node is to be considered as the root of the node
	int max_top = max(single_max, root->val + L + R);

	res = max(res, max_top);

	return single_max;
}


int maxPathSum(TreeNode* root) {
	int result = INT_MIN;
	dfs(root, result);
	return result;
}

/*
  TREE VISUALIZATION

       2   --> returns 4
	 /
   -1      --> returns -1+3
   /
  3        --> returns 3

 */
