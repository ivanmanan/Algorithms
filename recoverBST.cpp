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

    void swap(TreeNode* firstNode, TreeNode* secondNode) {
        int temp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = temp;
    }

    void inOrderTraversal(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node == NULL) {
            return;
        }
        inOrderTraversal(node->left, nodes);
        nodes.push_back(node);
        inOrderTraversal(node->right, nodes);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        // Do in-order traversal
        inOrderTraversal(root, nodes);

        // Find the nodes that are mis-aligned
        TreeNode* firstNode = new TreeNode(0);
        TreeNode* secondNode = new TreeNode(0);
        firstNode = NULL;
        secondNode = NULL;

        // Traverse from end -> beginning, finding first node smaller than previous element
        for (auto it = nodes.rbegin(); it != nodes.rend(); it++) {
            if (it+1 != nodes.rend()) {
                if ((*it)->val < (*(it+1))->val) {
                    firstNode = *it;
                    break;
                }
            } // Otherwise, first element in the vector is out of order
            else if (firstNode == NULL) {
                firstNode = *it;
            }
        }

        // Traverse from beginning -> end, finding first node larger than next element
        for (auto it = nodes.begin(); it != nodes.end(); it++) {
            if (it+1 != nodes.end()) {
                if ((*it)->val > (*(it+1))->val) {
                    secondNode = *it;
                    break;
                }
            } // Otherwise, last element in the vector is out of order
            else if (secondNode == NULL) {
                secondNode = *it;
            }
        }

        // Swap the nodes that are mis-aligned
        swap(firstNode, secondNode);
    }
};