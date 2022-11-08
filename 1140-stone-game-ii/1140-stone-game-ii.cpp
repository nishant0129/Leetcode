class Solution {
public:
    int helper(vector<int>&piles,int m,int idx,int aturn,vector<vector<vector<int>>>& dp)
    {
       if(idx >= piles.size())
           return 0;
        
        if(dp[idx][m][aturn] != -1)
            return dp[idx][m][aturn];
        
        if(aturn) 
        {  
            int ans = 0, sum = 0;   
            for(int i=idx; (i-idx) < 2*m && i < piles.size(); i++) 
            {
                sum += piles[i];
                ans = max(ans, sum + helper(piles, max((i-idx)+1, m), i+1, !aturn, dp));
            }
            dp[idx][m][aturn] = ans;
        } 
        else 
        {       
            int ans = INT_MAX;
            for(int i=idx;(i-idx) < 2*m && i < piles.size(); i++) 
            {
                ans = min(ans, helper(piles, max((i-idx)+1, m), i+1, !aturn, dp)); 
            }
            dp[idx][m][aturn] = ans;
        }
        
        return dp[idx][m][aturn];
    }
    int stoneGameII(vector<int>& piles) 
    {
      int sz = piles.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(2*sz, vector<int>(2, -1)));
        return helper(piles, 1, 0, 1, dp);
    }
};