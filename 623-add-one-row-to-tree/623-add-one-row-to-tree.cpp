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
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(depth==1) {
//             TreeNode* node=new TreeNode(val,root,NULL);
//             return node;
//         }
        
//         queue<TreeNode*>q;
//         q.push(root);
//         int level=1;
//         while(not q.empty()) {
//             int st=q.size();
//             for(int i=0;i<st;i++) {
//                 TreeNode * k=q.front();
//                 q.pop();
//                 if(level==depth-1 and k) {
//                     TreeNode *add1=new TreeNode(val);
//                     TreeNode *add2=new TreeNode(val);
//                     add1->left=k->left;
//                     add1->right=NULL;
//                     add2->left=NULL;
//                     add2->right=k->right;
//                     k->left=add1;
//                     k->right=add2;
//                 }else {
//                     if(k) {
//                         q.push(k->left);
//                         q.push(k->right);
//                     }
//                 } 
//             }
//             if(level==depth-1) {
//                 break;
//             }
//             level+=1;
//         }
//         return root;
//     }
// };


class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode*newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode*curr=q.front(); 
                q.pop();
                if(level!=depth-1)
                {
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                else
                {
                    TreeNode*node1=new TreeNode(val);
                    TreeNode*node2=new TreeNode(val);
                    node1->left=curr->left;
                    curr->left=node1;
                    node2->right=curr->right;
                    curr->right=node2;
                }
            }
            level++;
        }
        return root;
    }
};