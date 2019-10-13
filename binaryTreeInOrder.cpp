#include <iostream>
#include <vector>

using namespace std;

// NOTE: Always remember to check if pointer is NULL

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

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
};