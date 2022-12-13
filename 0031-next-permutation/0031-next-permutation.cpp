class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=-1;
        for(int i=n-1; i>0; i--)
        {
            if(nums[i-1]<nums[i])
            {
                k=i-1;
                break;
            }
        }
        if(k==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=-1;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i]>nums[k])
            {
                j=i;
                swap(nums[i],nums[k]);
                reverse(nums.begin()+k+1,nums.end());
                break;
            }
        }
        
    }
};