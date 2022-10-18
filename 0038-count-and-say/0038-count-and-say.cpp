class Solution {
public:
    string countAndSay(int n) {
        return rec(n,"1");
    }
    string rec(int n,string s)
    {
        if(n==1) return s;
        string ans="";
        int i=0,j;
        while(i<s.size())
        {
            j=i;
            while(i<s.size() && s[i]==s[j])
            {
                i++;
            }
            ans+=to_string(i-j)+s[j];
        }
        return rec(n-1,ans);
    }
};