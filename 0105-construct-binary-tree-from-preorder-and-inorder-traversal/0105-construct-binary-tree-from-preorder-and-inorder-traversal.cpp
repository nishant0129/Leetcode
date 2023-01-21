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
    TreeNode*solve(vector<int>&preorder,int &prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&mp)
    {
        if(prestart>preend||instart>inend) return NULL;
        int val=preorder[prestart++];
        int idx=mp[val];
        TreeNode* root=new TreeNode(val);
        root->left=solve(preorder,prestart,preend,inorder,instart,idx-1,mp);
        root->right=solve(preorder,prestart,preend,inorder,idx+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int prestart=0;
        return solve(preorder,prestart,n-1,inorder,0,n-1,mp);
    }
};