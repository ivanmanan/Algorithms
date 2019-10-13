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

    void traverse(TreeNode* Node, vector<int>& solution) {

        if (Node == NULL) {
            return;
        }

        // Visit parent node
        int value = Node->val;
        solution.push_back(value);

        // Visit left and right children
        traverse(Node->left, solution);
        traverse(Node->right, solution);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> solution;
        traverse(root, solution);
        return solution;
    }
};