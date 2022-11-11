class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size())
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
        int cnt=i;
        i++;
        
        return cnt+1;
    }
};