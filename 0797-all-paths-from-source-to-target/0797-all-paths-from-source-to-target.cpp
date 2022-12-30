class Solution {
public:
     void dfs(vector<vector<int>>& graph,vector<int>&vis,int src,vector<vector<int>>&ans,vector<int>&v) 
    {
        if(src==graph.size()-1)
        {   
            v.push_back(src);
            ans.push_back(v);
            return;
        }
        v.push_back(src);
        vis[src]=1;
        for(auto child:graph[src])
        {
            if(!vis[child])
            {
                dfs(graph,vis,child,ans,v);
                v.pop_back();
                vis[child]=0;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        vector<int>v,vis(n,0);
        dfs(graph,vis,0,ans,v);
        return ans;
    }
};