class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int total_sum=accumulate(nums.begin(),nums.end(),0ll),ct=0;
        int n=nums.size(),ans,mini=INT_MAX;
        for(int i=0;i<n;i++) {
            ct+=nums[i];
            long long int diff=(n-i-1)!=0 ? abs(ct/(i+1)-(total_sum-ct)/(n-i-1)):ct/(i+1);
            if(diff<mini) {
                mini=diff;
                ans=i;
            }
        }
        return ans;
    }
};