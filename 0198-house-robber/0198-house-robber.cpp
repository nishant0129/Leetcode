class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int take=nums[i]+solve(nums,i+2,dp);
        int notake=solve(nums,i+1,dp);
        return dp[i]=max(take,notake);
    }
    int rob(vector<int>& nums) {
        int csum=0;
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};