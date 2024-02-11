/*
    TIME: O(N), N = number of nodes
    SPACE: O(H), H = height of tree

    inorder: L P R

    Push elements into stack, and go all the way left until NULL.

    STACK: [7, 3]

    Pop top of stack. Push one element to the right, then all the way to the left again.
*/
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
    }

    int next() {
        TreeNode* curr = st.top();
        st.pop();
        int res = curr->val;

        if(curr->right != NULL) {
            curr = curr->right;
            while(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
        }
        return res;
    }

    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*> st;
};
