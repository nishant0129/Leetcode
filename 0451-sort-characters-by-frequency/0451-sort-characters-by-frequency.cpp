class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i:s)
            mp[i]++;
        vector<pair<int,char>>v;
        for(auto i:mp)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.rbegin(),v.rend());
        string ans="";
        for(auto i:v)
        {
            int x=i.first;
            while(x--)
            {
                ans+=i.second;
            }
        }
       return ans;
    }
};