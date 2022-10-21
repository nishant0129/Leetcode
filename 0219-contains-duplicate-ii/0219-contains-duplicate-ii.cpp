class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_map<int,vector<int>>mp;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     mp[nums[i]].push_back(i+1);
        // }
        // for(auto i:mp)
        // {
        //     vector<int>v=i.second;
        //     for(int i=1; i<v.size(); i++)
        //     {
        //         if(v[i]-v[i-1]<=k)
        //             return true;
        //     }
        // }
        // return false;
        
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++)
     {
          if(mp.find(nums[i])!=mp.end())
          {
             if(abs(mp[nums[i]]-i)<=k)
              return true;
            }
           mp[nums[i]]=i;
    }
    return false;
    }
};