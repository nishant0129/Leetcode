class Solution {
public:
    bool recur(vector<int>&nums,int idx,int n,vector<int>&dp)
    {
        if(idx>=n-1 )
            return true;
        if(nums[idx]==0)
            return false;
        if(dp[idx]!=-1)
            return dp[idx];
      for(int i=1;i<=nums[idx];i++){
            if(recur(nums,idx+i,n,dp)) 
                return  dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
          vector<int>dp(nums.size()+1,-1);
       return recur(nums,0,nums.size(),dp) ;
    }
};