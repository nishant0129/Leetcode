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
    
    bool inorder(TreeNode* root,long long int &prev)
    {
        if(!root)
            return true;
        bool flag=false,ok=false;
       flag=inorder(root->left,prev);
        if(root->val<=prev)
            return false;
        else
            prev=root->val;
       ok=inorder(root->right,prev);
        return ok&&flag;
        
    }
    
    
    bool isValidBST(TreeNode* root) {
   
     long long int prev=LLONG_MIN;
        return inorder(root,prev);
    }
};