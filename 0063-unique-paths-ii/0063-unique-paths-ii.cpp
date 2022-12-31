class Solution {
public:
  
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
      vector<vector<int>>dp(m,vector<int>(n,0));
        int i=0;
       while( i<m && grid[i][0]==0)
         {
           dp[i][0]=1;
           i++;
         }
     int j=0;
       while( j<n && grid[0][j]==0)
         {
           dp[0][j]=1;
           j++;
         }
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(grid[i][j]==1)
                    dp[i][j]=0;
                else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        //  for(int i=0; i<m; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //        cout<<dp[i][j]<<" ";
        //     }
        //      cout<<endl;
        // }
        return dp[m-1][n-1];
    }
};