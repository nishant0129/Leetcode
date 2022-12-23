class Solution {
public:
    int recur(vector<int>&prices,int i,int BUY,int n,vector<vector<int>>&dp)
    {
        if(i>=n)
            return 0;
        if(dp[i][BUY]!=-1)
            return dp[i][BUY];
        if(BUY)
        {
          int buy=recur(prices,i+1,0,n,dp)-prices[i];
          int nbuy=recur(prices,i+1,1,n,dp);
            return dp[i][BUY]=max(buy,nbuy);
        }
        else
        {
          
            int sell=prices[i]+recur(prices,i+2,1,n,dp);
            int nsell=recur(prices,i+1,0,n,dp);
            return dp[i][BUY]=max(sell,nsell);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return recur(prices,0,1,n,dp);
    }
};