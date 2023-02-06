class Solution {
public:
    bool solve(vector<int>&nums,int mid,int k)
    {
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                k--;
                sum=nums[i];
                if(sum>mid)
                    return false;
            }
        }
        if(k>0)
            return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0,h=1e9+10;
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