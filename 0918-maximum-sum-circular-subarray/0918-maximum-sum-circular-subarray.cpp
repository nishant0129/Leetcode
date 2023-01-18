class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum=INT_MIN,min_sum=INT_MAX,total_sum=0,curr_sum=0,n=nums.size();
        for(int i=0;i<n;i++) {
            total_sum+=nums[i];
            curr_sum+=nums[i];
            max_sum=max(curr_sum,max_sum);
            if(curr_sum<0) curr_sum=0;
        }
        curr_sum=0;
        for(int i=0;i<n;i++) {
            curr_sum+=nums[i];
            min_sum=min(curr_sum,min_sum);
            if(curr_sum>0) curr_sum=0;
        }
        
        if(total_sum==min_sum) {
            return max_sum;
        }
        return max(max_sum,total_sum-min_sum);
    }
};