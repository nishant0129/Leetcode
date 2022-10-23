class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        int rep=0;
        for(int i=0; i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
            {
                rep=nums[i];
                break;
                
            }
        }
        int xorr=0;
       for(int i=0; i<nums.size();i++)
       {
           xorr^=(nums[i]);
           xorr^=(i+1);
       }
        int mis=xorr^rep;
        return {rep,mis};
    }
};