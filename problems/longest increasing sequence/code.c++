class Solution {
public:
    int find(vector<int>&nums,int val)
    {
        int l=0;
        int r=nums.size()-1;
        int index=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==val)
            {
                return mid;
            }
            else if(nums[mid]<val)
            {
                l=mid+1;
            }
            else
            {
                index=mid;
                r=mid-1;
            }
        }
        return index;
    }
    int lengthOfLIS(vector<int>& nums) 
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
                //int index=find(ans,nums[i]);
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
};