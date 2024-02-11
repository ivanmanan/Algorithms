#include "globals.h"

TreeNode* sortedArrayToBST(vector<int>& nums) {


	int len = nums.size();

	if (len == 0)
		return NULL;

	if (len == 1) {
		TreeNode * root = new TreeNode(nums[0]);
		root->left = root->right = NULL;

		return root;
	}

	int mid = len / 2;

	TreeNode * root = new TreeNode(nums[mid]);

	vector<int> left(nums.begin(),nums.begin()+mid);
	vector<int> right(nums.begin()+mid+1,nums.end());

	root->left = sortedArrayToBST(left);
	root->right = sortedArrayToBST(right);

	return root;
}