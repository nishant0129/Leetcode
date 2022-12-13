class Solution {
public:
    int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp)
    {
        int n=matrix.size();
        if(i<0 || j<0 || i>n-1 || j>n-1) return INT_MAX;
        if(i == n-1) return matrix[i][j];
       
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=matrix[i][j]+min({dfs(matrix,i+1,j-1,dp),dfs(matrix,i+1,j,dp),dfs(matrix,i+1,j+1,dp)});
    
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       for(int i=0; i<n;i++) 
       {
           ans=min(ans,dfs(matrix,0,i,dp));
           
       }
        return ans;
    }
};