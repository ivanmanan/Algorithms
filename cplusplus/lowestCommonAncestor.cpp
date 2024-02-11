#include "TreeNode.h"

/*

    1   2       3      4    5

    4 -> 2 ->
              [ 5 ] -> 3 -> NULL
         6 ->

         6      7      8


    5   6       7      8

    4 -> 2 ->
              [ 5 ] -> 3 -> NULL
         6 ->

         1      2      3    4
*/

// Lowest Common Ancestor III - Only given the two node pointers
// This is essentially the intersection of two linked lists
Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* l1 = p;
    Node* l2 = q;

    while(l1 != l2) {
        if(l1 != NULL) {
            l1 = l1->parent;
        }
        else {
            l1 = q;
        }
        if(l2 != NULL) {
            l2 = l2->parent;
        }
        else {
            l2 = p;
        }
    }
    return l1;
}


// Lowest Common Ancestor I - Given root node and two node pointers
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) {
        return NULL;
    }
    if(root == p || root == q) {
        return root;
    }
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if(l != NULL && r != NULL) {
        return root;
    }
    if(l != NULL) {
        return l;
    }
    else {
        return r;
    }
}

// BFS to find the nodes on the deepest level
// leftmost and rightmost
// Then do LCA
TreeNode* subtreeWithAllDeepest(TreeNode* root) {

    list<TreeNode*> dq;
    TreeNode* leftmost;
    TreeNode* rightmost;
    dq.push_back(root);
    int level = 0;
    while(!dq.empty()) {
        leftmost = dq.front();
        rightmost = dq.back();
        int curr_size = dq.size();
        for(int i = 0; i < curr_size; i++) {
            TreeNode* curr = dq.front();
            dq.pop_front();
            if(curr->left != NULL) {
                dq.push_back(curr->left);
            }
            if(curr->right != NULL) {
                dq.push_back(curr->right);
            }
        }
    }

    return lowestCommonAncestor(root, leftmost, rightmost);
}
