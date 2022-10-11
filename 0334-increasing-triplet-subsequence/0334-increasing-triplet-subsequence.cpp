class Solution {
public:
    // int lis(vector<int>&nums,int prev,int cur,vector<vector<int>>&dp)
    // {
    //     if(cur==0)
    //         return false;
    //     int take=0,nottake=0;
    //     if(dp[cur][prev+1]!=-1)
    //         return dp[cur][prev+1];
    //     if(prev==-1||nums[cur]>nums[prev])
    //     {
    //        take=1+lis(nums,cur,cur+1);
    //     }
    //     else 
    //     {
    //         nottake=lis(nums,prev,cur+1);
    //     }
    //     return dp[cur][prev+1]=take+nottake;
    // }
    bool lis(vector<int>& nums) 
    {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(ans.back()<nums[i])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
            if(ans.size()>=3)
                return true;
        }
        return false;
    }
    bool increasingTriplet(vector<int>& nums) {
       return lis(nums);
    }
};