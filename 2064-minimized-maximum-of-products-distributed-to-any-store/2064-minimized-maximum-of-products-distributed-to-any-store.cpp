class Solution {
public:
    bool solve(vector<int>&nums,int n,int mid)
    {
        int i=0,j=nums.size();
        int cnt=0;
        while(i<j)
        {
            cnt+=ceil((double)nums[i]/mid);
            i++;
        }
        if(cnt<=n)
            return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,h=*max_element(quantities.begin(),quantities.end()),ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(solve(quantities,n,mid))
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