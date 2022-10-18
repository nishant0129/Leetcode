class Solution {
public:
    string solve(int n,string s)
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
        return solve(n-1,ans);
    }
    string countAndSay(int n) {
        return solve(n,"1");
    }
   
};