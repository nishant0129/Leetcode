class Solution {
public:
    bool solve(vector<int>&nums,int mid,int k)
    {
        int l=0,r=nums.size();
        while(l<r)
        {
            if(nums[l]<=mid)
                l+=2,k--;
            else
                l+=1;
            if(k==0)
                return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=0,h=1e9+1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(solve(nums,mid,k))
                h=mid;
            else
                l=mid+1;
        }
        return l;
    }
};