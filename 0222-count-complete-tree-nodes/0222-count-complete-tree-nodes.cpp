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
    // int countNodes(TreeNode* root) {
    //     if(!root)
    //         return 0;
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     int cnt=0;
    //     while(!q.empty())
    //     {
    //         int sz=q.size();
    //         TreeNode* cur=q.front();
    //         q.pop();
    //         cnt++;
    //         if(cur->left)q.push(cur->left);
    //         if(cur->right)q.push(cur->right);
    //     }
    //     return cnt;
    // }

        int countNodes(TreeNode* root) {
        if(!root)
            return 0;
            return 1+countNodes(root->left)+countNodes(root->right);
    }
};