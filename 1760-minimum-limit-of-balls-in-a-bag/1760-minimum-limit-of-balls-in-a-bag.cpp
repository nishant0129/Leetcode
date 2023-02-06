class Solution {
public:
    bool solve(vector<int>&nums,int mid,int k)
    {
        int i=0,j=nums.size();
        while(i<j)
        {
            if(mid>=nums[i])
            {
                
            }
            else
            {
                int z=nums[i]/mid;
               if(nums[i]%mid==0)
                k-=z-1;
                else
                    k-=z;
                
            }
            i++;
        
        }
        if(k>=0)
            return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,h=1e9+1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(solve(nums,mid,maxOperations))
            {
                h=mid;
            }
            else
                l=mid+1;
        }
        return l;
    }
};