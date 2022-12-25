class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int>ans;
        for(auto i:queries)
        {
            int idx= upper_bound(prefix.begin(),prefix.end(),i)-prefix.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};