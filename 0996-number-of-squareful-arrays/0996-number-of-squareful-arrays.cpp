class Solution {
public:
    bool isPer(int n)
    {
        int x=sqrt(n);
        return x*x==n;
    }
    void solve(vector<int>nums,int idx,int &ans)
    {
        if(idx>=nums.size())
        {
            ans++;
            return;
        }
         for(int i=idx; i< nums.size(); i++)
         {
            if(i > idx && nums[i] == nums[idx])
                    continue;
             
                swap(nums[i], nums[idx]);

                if(idx == 0 || (idx > 0 && isPer(nums[idx] + nums[idx - 1])))
                    solve(nums, idx + 1, ans);     
         }
       
   }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        solve(nums,0,ans);
        return ans;
    }
};