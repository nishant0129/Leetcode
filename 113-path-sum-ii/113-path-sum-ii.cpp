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
 void helper(TreeNode* root ,int tsum,int csum,vector<int>&p,vector<vector<int>>&res)
  {
        if(!root)
            return;
        csum+=root->val;
     p.push_back(root->val);
     if(csum==tsum && !root->left && !root->right)
     {
         res.push_back(p);
     }
     helper(root->left,tsum,csum, p,res);
       helper(root->right,tsum,csum, p,res);
     p.pop_back();
     csum-=root->val;
         
  }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int>p;
        vector<vector<int>>res;
        helper(root,targetSum,0,p,res);
        return res;
         
    }
   
};