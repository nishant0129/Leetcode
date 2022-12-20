class Solution {
public:
    void print(vector<vector<int>>&adj)
    {
        for(auto i:adj)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
    }
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
        vector<vector<int>>adj(rooms.size());
        int k=0;
        for(auto v:rooms)
        { 
          for(auto i:v)
          {
            adj[k].push_back(i);
              
          }
            k++;
        }
        vector<bool>vis(rooms.size(),false);
        vis[0]=true;
       // print(adj);
         dfs(adj,vis,0);
        for(auto i:vis)
        {
            if(i==false)
                return false;
        }
        return true;
    }
};