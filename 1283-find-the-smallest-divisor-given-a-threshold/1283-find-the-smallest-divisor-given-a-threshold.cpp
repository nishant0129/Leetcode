class Solution {
public:
    bool solve(vector<int>&nums,int th,int mid)
    {
        int i=0,j=nums.size();
        int cnt=0;
        while(i<j)
        {
            cnt+=ceil((double)nums[i]/mid);
            i++;
        }
        if(cnt<=th)
            return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=*max_element(nums.begin(),nums.end()),ans=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(solve(nums,threshold,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};