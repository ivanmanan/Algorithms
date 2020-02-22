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

    void DFS(TreeNode* node, vector<int>& numbers, int depth, int sum) {

        if (node == NULL) {
            return;
        }

        // Leaf node
        if (node->right == NULL && node->left == NULL) {

            // Add final value to sum
            sum += node->val * pow(10, depth);

            // Reverse the sums here and push back to numbers
            int remainder = 0;
            int reverse = 0;
            while (sum != 0) {
                remainder = sum % 10;
                reverse = reverse * 10 + remainder;
                sum = sum / 10;
            }

            // If the leaf node was zero
            if (node->val == 0) {
                reverse = reverse * 10;
            }

            numbers.push_back(reverse);
            return;
        }


        // Increment Depth
        if (node->left != NULL || node->right != NULL) {
            // Input the root to leaf nodes by reverse
            sum += node->val * pow(10, depth);
            ++depth;
        }

        // Do Left Subtree
        if (node->left != NULL) {
            DFS(node->left, numbers, depth, sum);
        }

        // Do Right Subtree
        if (node->right != NULL) {
            DFS(node->right, numbers, depth, sum);
        }

    }

    int sumNumbers(TreeNode* root) {
        vector<int> numbers;
        DFS(root, numbers, 0, 0);

        int totalSum = 0;
        for (auto it = numbers.begin(); it != numbers.end(); it++) {
            totalSum += *it;
        }

        return totalSum;
    }
};