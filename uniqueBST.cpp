#include "TreeNode.h"

class Solution {
public:
    TreeNode* clone(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);
        return newroot;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n<1) return vector<TreeNode*>{};
        vector<vector<TreeNode*>> dp(n);
        dp[0].push_back(new TreeNode(1));
        for (int i = 1; i<n; i++) {
            TreeNode* root = new TreeNode(i + 1);
            // step 1
            for (int j = 0; j<dp[i - 1].size(); j++) {
                root->left = clone(dp[i - 1][j]);
                dp[i].push_back(root);
                root = new TreeNode(i + 1);
            }
            //step 2
            for (int j = 0; j<dp[i - 1].size(); j++) {
                TreeNode* newroot = clone(dp[i - 1][j]);
                TreeNode* preroot = newroot;
                while (newroot->right != NULL)
                    newroot = newroot->right;
                newroot->right = root;
                dp[i].push_back(preroot);
            }
            root = new TreeNode(i + 1);
            //step 3
            for (int j = 0; j<dp[i - 1].size(); j++) {
                TreeNode* newroot = clone(dp[i - 1][j]);
                TreeNode* preroot = newroot;
                int count =1;
                while (preroot != NULL ) {
                    int z=count;
                    if (preroot->val == i)
                        break;
                    TreeNode* nextnode = clone(newroot);
                    TreeNode* begin = nextnode;
                    TreeNode* tt;
                    while(z!=0){
                        if(z-1==0)
                            tt=nextnode;
                        nextnode=nextnode->right;
                        z--;
                    }
                    tt->right=root;
                    root->left=nextnode;
                    dp[i].push_back(begin);
                    preroot=preroot->right;
                    root=new TreeNode(i+1);
                    count++;
                }
            }
        }
        return dp[n - 1];
    }
};