class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string res;
        for(int i=0; i<s.size(); i++)
        {
            res="";
            while(i<s.size() && s[i]!=' ')
            {
                res+=s[i];
                i++;
            }
            reverse(res.begin(),res.end());
            ans+=res+" ";
        }
        ans.pop_back();
        // ans+=res;
        return ans;
    }
};