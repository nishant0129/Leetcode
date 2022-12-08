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
 
//     void dfs(TreeNode* root, string &s) 
//     {
//         if(root==NULL) 
//             return;
//         dfs(root->left, s);
//         if(!root->left&& !root->right)
//             s+=to_string(root->val);
        
//         dfs(root->right, s);
//     }
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         string t1="", t2="";
//         dfs(root1, t1);
//         dfs(root2, t2);
//         if(t1==t2)
//             return true;
//         return false;
//     }
   class Solution {
public:
    void dfs(TreeNode* root, vector<int>& v) {
        if (!root) return;
        if ((!root->left&& !root->right)) {
            v.push_back(root->val);
        }
        dfs(root->left, v);
        dfs(root->right, v);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1{};
        vector<int> v2{};
        
        dfs(root1, v1);
        dfs(root2, v2);
        
        return v1 == v2;
        
    }
};