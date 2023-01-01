class Solution {
public:
    const long long int mod=1e9+7;
    long long int solve(vector<int>&nums,int k,int i,long long int csum, vector<vector<int>>&dp)
    {
        if(csum>=k)
        return 0;
        
        if(i>=nums.size())
        return csum<k;
        
        if(dp[i][csum]!=-1)
        return dp[i][csum];
        
        int take=solve(nums,k,i+1,csum+nums[i],dp)%mod;
        int ntake=solve(nums,k,i+1,csum,dp)%mod;
        return dp[i][csum]=(take+ntake)%mod;
    }
    int countPartitions(vector<int>& nums, int k) {
        long long int tsum=0;
        for(auto i:nums)
            tsum+=i;
        if(tsum<2*k)
            return 0;
       //vector<int>v;
       // map<vector<int>,int>mp;
        vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));
        long long int cnt=solve(nums,k,0,0,dp);
            cnt=(cnt*2)%mod;
        long long int ts=1;
       for(int i=0; i<nums.size(); i++)
       {
           ts=(ts*2)%mod;
       }
        int res=ts-cnt;
        if(res<0)
            res+=mod;
        return res;
    }
};