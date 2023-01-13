class Solution {
public:
    int ans;
    int dfs(vector<vector<int>>&adj,string &s,int curr_node,int parent)
    {
        int fmax=0,smax=0;  

        for(auto child:adj[curr_node]) { 

            if(child==parent) 
                continue;
            int temp=dfs(adj,s,child,curr_node); 

            if(s[child]!=s[curr_node]) 
            {
                if(temp>=fmax) 
                {
                    smax=fmax;
                    fmax=temp;
                }
                else if(temp>=smax)
                    smax=temp;
            }
        }

        ans=max(ans,1+fmax+smax);
        return 1+fmax;
    }
    int longestPath(vector<int>& parent, string s) {
       
        vector<vector<int>>adj(parent.size());
        for(int i=1; i<parent.size(); i++)
        {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        vector<int>vis(26,0);
        ans=0;
        dfs(adj,s,0,-1);
        
        return ans;
    }
};