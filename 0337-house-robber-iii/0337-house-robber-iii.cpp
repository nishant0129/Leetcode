/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int norob=solve(root->left)+solve(root->right);
        int rob=root->val;
        if(root->left)
            rob+=solve(root->left->left)+solve(root->left->right);
        if(root->right)
            rob+=solve(root->right->left)+solve(root->right->right);
        return dp[root]= max(norob,rob);
    }
    int rob(TreeNode* root) {
       
       return solve(root);
    }
};