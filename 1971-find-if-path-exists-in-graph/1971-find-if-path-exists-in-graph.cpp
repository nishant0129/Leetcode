class Solution {
public:
    bool dfs(vector<int>adj[],int s,int d,vector<bool>&vis)
    {
        vis[s]=true;
        if(s==d)
            return true;
         bool flag = false;
        for(auto child:adj[s])
        {
            if(!vis[child])
            {
                       flag|= dfs(adj,child,d,vis);
            }
        
        }
        return flag;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        if(source == destination) return true;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis(n,false);
       return dfs(adj,source,destination,vis);
    }
};