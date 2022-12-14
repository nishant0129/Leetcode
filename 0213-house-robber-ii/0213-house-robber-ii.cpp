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
        if(nums.size()==1)
            return nums[0];
     
        vector<int>a(nums.begin()+1,nums.end());
        vector<int>b(nums.begin(),nums.end()-1);
        vector<int>dp(nums.size()+1,-1);
        int ab=solve(a,0,dp);
        vector<int>dp1(nums.size()+1,-1);
        int ba=solve(b,0,dp1);
        
        return max(ab,ba);
    }
};
 