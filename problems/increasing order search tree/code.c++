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
            
    TreeNode*res=new TreeNode(-1);
   TreeNode*ans=res;
    void inorder(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void fun(TreeNode* &nishant,int i,vector<int>&ans)
    {
            if(i==ans.size())return ;
            TreeNode* temp=new TreeNode(ans[i]);
            nishant=temp;
        fun(nishant->right,i+1,ans);
            
    }
    TreeNode* increasingBST(TreeNode* root)
    {
        vector<int>ans;
       inorder(root,ans);
        TreeNode* nishant;
        fun(nishant,0,ans);
        
        return nishant;
    
    }
};