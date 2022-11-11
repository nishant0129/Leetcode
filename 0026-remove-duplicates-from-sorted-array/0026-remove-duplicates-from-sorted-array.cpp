class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            if(nums[i]==nums[j])
            {
                j++;
            }
            else
            {
                i++;
                swap(nums[i],nums[j]);
                j++;
            }
        }
        i++;
        
        return i;
    }
};