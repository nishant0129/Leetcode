class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans=s;
        if(k==1)
        {
            for(int i=1; i<s.size();i++)
            {
                s=s.substr(1)+s[0];
                ans=min(ans,s);
            }
        }
        else
        {
            sort(s.begin(),s.end());
            ans=s;
        }
        return ans;
    }
};