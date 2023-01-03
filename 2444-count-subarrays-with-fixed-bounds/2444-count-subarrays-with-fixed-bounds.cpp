class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        bool flag1=false,flag2=false;
        long long int left=0,minidx=0,maxidx=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<minK||nums[i]>maxK)
            {
                flag1=false;
                flag2=false;
                left=i+1;
            }
            if(nums[i]==minK)
            {
                flag1=true;
                minidx=i;
            }
            if(nums[i]==maxK)
            {
                flag2=true;
                maxidx=i;
            }
            if(flag1 and flag2)
            ans+=(min(minidx,maxidx)-left+1);
        }
        return ans;
    }
};