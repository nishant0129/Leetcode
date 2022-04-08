class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
       long long temp=INT_MAX;
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            int l=i+1;
            int r=n-1;
            int sum=0;
            while(l<r)
            {
                sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                  return sum;
                if(temp>abs(target-sum))
                {
                    temp=abs(sum-target);
                    ans=sum;}
                else if(sum>target)
                    r--;
                 else
                    l++;
             }
         }
         return ans;
    }
};