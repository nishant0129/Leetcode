//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    
    void dfs(int curr,vector<bool>&visited,vector<int>adj[]) {
        visited[curr]=true;
        for(auto ch:adj[curr]) {
            if(not visited[ch]) dfs(ch,visited,adj);
        }
    }
    
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool>visited(V,false);
        visited[c]=true;
        for(auto ch:adj[c]) {
            if(ch==d) continue;
            dfs(ch,visited,adj);
        }
        return !visited[d];
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends