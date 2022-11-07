class Solution {
public:
    int recur(vector<int>&nums,int l,int r,int sum)
    {
        if(l>r)
            return 0;
        return sum-min(recur(nums,l+1,r,sum-nums[l]),recur(nums,l,r-1,sum-nums[r]));
        //return max(nums[l]+min(dfs(l+2,r,nums),dfs(l+1,r-1,nums)),nums[r]+min(dfs(l,r-2,nums),dfs(l+1,r-1,nums)));   
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int p1=recur(nums,0,nums.size()-1,sum);
        int p2=sum-p1;
        return p1>=p2;
    }
};