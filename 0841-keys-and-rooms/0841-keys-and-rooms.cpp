class Solution {
public:
    
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int s)
    {
         vis[s]=true;
        for(auto child:adj[s])
        {
            if(!vis[child])
            dfs(adj,vis,child);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        vector<bool>vis(rooms.size(),false);
      
       // print(adj);
         dfs(rooms,vis,0);
        for(auto i:vis)
        {
            if(i==false)
                return false;
        }
        return true;
    }
};