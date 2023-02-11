//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool valid(int x,int y,int n)
    {
        if(x>=1 && y>=1 && x<=n && y<=n)
        return true;
        return false;
    }
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int N)
	{
	    // Code here
	    pair<int,int>dirs[8]={{-1,-2},{-1,2},{-2,-1},{-2,1},{1,-2},{1,2},{2,-1},{2,1}};
	    queue<pair<int,int>>q;
	    q.push({kp[0],kp[1]});
	    int cdis=0;
	    vector<vector<int>>vis(N,vector<int>(N,0));
	    vis[kp[0]-1][kp[1]-1]=1;
	    while(!q.empty())
	    {
	        int sz=q.size();
	        while(sz--)
	        {
	            auto cur=q.front();
	            q.pop();
	            int x=cur.first,y=cur.second;
	            if(x==tp[0] && y==tp[1])
	            return cdis;
	            for(auto dir : dirs)
	            {
	                int nx=x+dir.first;
	                int ny=y+dir.second;
	                if(valid(nx,ny,N) && !vis[nx-1][ny-1] )
	                {
	                    q.push({nx,ny});
	                    vis[nx-1][ny-1]=1;
	                    
	                }
	            }
	        }
	        cdis++;
	    }
	    return cdis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends