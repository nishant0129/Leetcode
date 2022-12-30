class Solution {
public:
     void dfs(vector<vector<int>>& graph,int src,vector<vector<int>>&ans,vector<int>&v) 
    {
        if(src==graph.size()-1)
        {   
            v.push_back(src);
            ans.push_back(v);
            return;
        }
        v.push_back(src);
     
        for(auto child:graph[src])
        {
                dfs(graph,child,ans,v);
                v.pop_back();
            
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>v;
        dfs(graph,0,ans,v);
        return ans;
    }
};