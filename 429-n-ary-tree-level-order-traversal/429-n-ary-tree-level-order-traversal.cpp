/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root,map<int,vector<int>>&mp,int level)
    {
        if(!root)
            return;
        mp[level].push_back(root->val);
         for (Node* child : root->children)
            solve(child,mp,level+1);
            
        
    }
    vector<vector<int>> levelOrder(Node* root) {
        map<int,vector<int>>mp;
        vector<vector<int>>ans;
        solve(root,mp,0);
        for(auto i:mp)
        {
            vector<int>v;
            for(auto j:i.second)
                v.push_back(j);
            ans.push_back(v);
        }
        return ans;
    }
};