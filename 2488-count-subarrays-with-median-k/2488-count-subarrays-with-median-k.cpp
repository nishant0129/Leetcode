class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int idx=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==k)
            {
                idx=i;
                break;
            }
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>k)
                nums[i]=1;
            else if(nums[i]==k)
                nums[i]=0;
            else 
                nums[i]=-1;
        }
        
        unordered_map<int,int>mp;
        int csum=0;
        for(int i=idx; i>=0; i--)
        {
            csum+=nums[i];
            mp[csum]++;
        }
        csum=0;
        int ans=0;
        for(int i=idx; i<nums.size(); i++)
        {
            csum+=nums[i];
            int nd=-1*csum;
            ans+=mp[nd]+mp[nd+1];
        }
        return ans;
    }
};