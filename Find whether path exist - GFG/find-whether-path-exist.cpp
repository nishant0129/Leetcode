//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool valid(int x,int y,int n)
    {
        if(x>=0 && x<n && y>=0 && y<n)
        return true;
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        pair<int,int>dir[4]={{1,0},{0,1},{-1,0},{0,-1}};
        pair<int,int>des,src;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    src={i,j};
                }
                if(grid[i][j]==2)
                   des={i,j};
            }
        }
        queue<pair<int,int>>q;
        q.push(src);
        vis[src.first][src.second]=1;
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int x=cur.first;
            int y=cur.second;
            if(x==des.first && y==des.second)
            return true;
            for(auto i:dir)
            {
                int nx=x+i.first;
                int ny=y+i.second;
                if(valid(nx,ny,grid.size()) && !vis[nx][ny] && grid[nx][ny]!=0)
                {
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends