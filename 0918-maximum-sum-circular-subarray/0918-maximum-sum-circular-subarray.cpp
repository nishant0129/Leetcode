class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res=INT_MIN,sum=0;
        int tsum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size(); i++)
        {
            sum+=nums[i];
            res=max(res,sum);
            if(sum<0)
                sum=0;
                
        }
        int sum1=0,res1=INT_MAX;
         for(int i=0;i<nums.size(); i++)
        {
            sum1+=nums[i];
            res1=min(res1,sum1);
            if(sum1>0)
                sum1=0;
                
        }
        
        return tsum!=res1?max(res,tsum-res1):res;
    }
};