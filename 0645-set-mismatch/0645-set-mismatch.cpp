class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        int rep=0;
        set<int>s;
        for(int i=0; i<nums.size();i++)
        {
            s.insert(nums[i]);
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
            {
                rep=nums[i];
                
            }
        }
       for(int i=1; i<=nums.size();i++)
       {
           if(s.find(i)==s.end())
           {
               return {rep,i};
           }
       }
        return {};
    }
};