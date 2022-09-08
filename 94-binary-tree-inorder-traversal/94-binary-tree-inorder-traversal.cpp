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
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
        
//     }
// };

// Iterative 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(!root) return ans;
        while(true) 
        {
            if(root)
            {
                st.push(root);
                root=root->left;       
            }else
            {
                if(st.empty()) 
                {
                    break;
                }
                else
                {
                    root=st.top();
                    ans.push_back(root->val);
                    st.pop();
                    root=root->right;
                    
                }
            }
        }
        return ans;
    }
};