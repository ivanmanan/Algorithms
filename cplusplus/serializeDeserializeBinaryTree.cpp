#include "globals.h"


// preorder - P L R
// inorder - L P R
// postorder - L R P

void dfs(TreeNode* root, vector<int>& preorder) {
    if(root == NULL) {
        preorder.push_back(NULL);
        return;
    }
    preorder.push_back(root->val);
    dfs(root->left, preorder);
    dfs(root->right, preorder);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    // Construct preorder tree traversal
    vector<int> preorder;
    dfs(root, preorder);

    string res = "";
    for(int i = 0; i < preorder.size(); i++) {
        if(preorder[i] == NULL) {
            res = res + "*" + ",";
        }
        else {
            res = res + to_string(preorder[i]) + ",";
        }
    }
    return res;
}

TreeNode* dfs_deserialize(queue<int>& preorder) {
    if(preorder.empty()) {
        return NULL;
    }
    int value = preorder.front();
    preorder.pop();
    cout << value << ";";
    if(value == NULL) {
        return NULL;
    }
    else {
        // P L R
        TreeNode* root = new TreeNode(value);
        root->left=dfs_deserialize(preorder);
        root->right=dfs_deserialize(preorder);
        return root;
    }
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    queue<int> preorder;

    string s = "";
    cout << "DATA: " << data << endl;
    for(int i = 0; i < data.length(); i++) {
        if(data[i] == ',') {
            if(s == "*") {
                preorder.push(NULL);
            }
            else {
                preorder.push(stoi(s));
            }
            s="";
            continue;
        }
        s += data[i];
    }


    TreeNode* head = dfs_deserialize(preorder);
    return head;
}
