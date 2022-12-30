class Solution {
public:
    const int MOD = 1e9+7;
    int dfs(vector<vector<int>>& grid,int i,int j,  vector<vector<int>>&dp)
    {
        int m=grid.size(),n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n)
            return 0 ;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=0,down=0,left=0,right=0;
        
        if(i+1<m && grid[i+1][j]>grid[i][j] )
            down=dfs(grid,i+1,j,dp)%MOD;
        
        if(i-1>=0 && grid[i-1][j]>grid[i][j])
            up=dfs(grid,i-1,j,dp)%MOD;
        
        if(j+1<n && grid[i][j+1]>grid[i][j])
            right=dfs(grid,i,j+1,dp)%MOD;
        
        if(j-1>=0 && grid[i][j-1]>grid[i][j])
            left=dfs(grid,i,j-1,dp)%MOD;
            
        return dp[i][j]=1+left+right+up+down;
    }
    int countPaths(vector<vector<int>>& grid) {
     int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<m;j++)
            {
                ans=ans%MOD + dfs(grid,i,j,dp)%MOD;
            }
        }
        return ans;
    }
};