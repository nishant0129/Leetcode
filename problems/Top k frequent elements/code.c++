class Solution { 
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>p;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            p.push({i.second,i.first});
        }
         vector<int> ans;
    int i = 0;
    while (!p.empty() && i != k)
    {
        ans.push_back(p.top().second);
        p.pop();
        i++;
    }
    return ans;
    }
    };