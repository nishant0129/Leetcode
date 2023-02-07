class Solution {
public:
    bool solve(vector<int>&arr,int m,int k,int mid)
    {
        int i=0,j=arr.size(),ct=0;
        while(i<j)
        {
            if(arr[i]<=mid)
            {
                ct++;
                if(ct==k)
                {
                    ct=0;
                    m--;
                    if(m==0)
                        return true;
                }
            }
            else
            {
                ct=0;
            }
            i++;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1,h=1e9+1,ans=-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(solve(bloomDay,m,k,mid))
            {
                ans=mid;
                h=mid;
            }
            else
            {
               l=mid+1;
            }
        }
        return ans;
    }
};