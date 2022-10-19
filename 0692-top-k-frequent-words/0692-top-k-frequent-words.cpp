class Solution {
public:
    static bool cmp(pair<int,string>a,pair<int,string>b)
    {
        if(a.first!=b.first)
            return a.first>b.first;
        else
            return b.second>a.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto &i: words)
        {
            mp[i]++;
        }
        vector<pair<int,string>>res;
        for(auto i:mp)
        {
            res.push_back({i.second,i.first});
        }
        sort(res.begin(),res.end(),cmp);
        vector<string>ans;
        for(auto &i:res)
        {
            ans.push_back(i.second);
            k--;
            if(k==0)
                break;
        }
        return ans;
    }
};