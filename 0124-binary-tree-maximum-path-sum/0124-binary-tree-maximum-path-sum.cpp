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
    int res=INT_MIN;
    int dfs(TreeNode *root)
    {
        if(root==NULL) return 0;
        int a=dfs(root->left);
        int b=dfs(root->right);
        res=max(res,a+b+root->val);
        return max(0,max(a, b)+root->val);
    }
    int maxPathSum(TreeNode *root)
    {
        if(root==NULL) return 0;
        dfs(root);
        return res;
    }
};