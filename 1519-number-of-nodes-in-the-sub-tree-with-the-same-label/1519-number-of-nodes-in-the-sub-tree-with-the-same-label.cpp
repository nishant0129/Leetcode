class Solution {
public:
    vector<int>ans;
    vector<int> dfs(vector<vector<int>>&adj,string &labels,int i,int parent)
    {
        vector<int>cur_vect(26,0);
        for(auto ch:adj[i])
        {
            if(parent==ch)
                continue;
            vector<int>temp=dfs(adj,labels,ch,i);
            
            for(int j=0;j<26;j++)
                cur_vect[j]+=temp[j];
        }
        cur_vect[labels[i]-'a']++;
        ans[i]=cur_vect[labels[i]-'a'];
        return cur_vect;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
 
        vector<vector<int>>adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans.resize(n,0);
        dfs(adj,labels,0,-1);
        return ans;
    }
};