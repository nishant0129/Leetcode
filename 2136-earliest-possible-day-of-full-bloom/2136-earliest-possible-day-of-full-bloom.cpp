class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        int cd=0;
        int ans=0;
        for(int i=0; i<plantTime.size();i++)
        {
            v.push_back({growTime[i],plantTime[i]});
        }
        sort(v.rbegin(),v.rend());
        for(int i=0; i<v.size(); i++)
        {
            cd+=v[i].second;
            ans=max(ans,cd+v[i].first);
        }
        
        return ans;
    }

};