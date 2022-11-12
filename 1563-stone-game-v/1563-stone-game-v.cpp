class Solution {
public:
    int solve(vector<int>&v,int tsum,int i,int j,vector<vector<int>>&dp)
    {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int csum = 0;   
        int ans = 0,score=0;
        for(int k=i; k<=j;k++)
        {
            csum += v[k];
			int sum1 = csum;     //sum of partition 1
            int sum2 = tsum-sum1;     //sum of partition 2
            if(sum1 > sum2)
               score = sum2 + solve(v , sum2 , k+1 , j , dp);
            else if(sum1 < sum2)
                score = sum1 + solve(v , sum1 , i , k , dp);
            else
                score = max(sum1 + solve(v , sum1 , i , k , dp) , sum2 + solve(v , sum2 , k+1 , j , dp));
            ans = max(ans , score);
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& sv) {
        vector<vector<int>> dp(sv.size() + 1 , vector<int>(sv.size() + 1 , -1));
        int tsum=accumulate(sv.begin(),sv.end(),0);
        return solve(sv,tsum,0,sv.size()-1,dp);
    }
};