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
    void solve(TreeNode* &root,int &cnt,int prev)
    {
         if(!root)return ;
         if(root->val >=prev)
         {
             cnt++;
             prev=root->val;
         }
        solve(root->left,cnt,prev);
        solve(root->right,cnt,prev);
    }
    int goodNodes(TreeNode* root) {
        int cnt=0,prev=INT_MIN;
        solve(root,cnt,prev);
        return cnt;
    }
};