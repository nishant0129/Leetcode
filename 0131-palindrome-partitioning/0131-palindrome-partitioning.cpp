class Solution {
public:
    bool is_palin(int idx,int i,string &s)
    {
        while(idx<=i)
        if(s[idx++]!=s[i--])
            return false;
        return true;
    }
    void solve(string s,int idx,vector<vector<string>>&ans,vector<string>&cur)
    {
        if(idx==s.size())
        {
            ans.push_back(cur);
            return;
        }
        for(int i=idx; i<s.size(); i++)
        {
            if(is_palin(idx,i,s))
            {
                cur.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,ans,cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        solve(s,0,ans,cur);
        return ans;
        
    }
};