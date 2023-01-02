class Solution {
public:
    bool isvalid(string s)
    {
        int cnt=0;
        int a=s[0]-'a';
        
        for(int i=1; i<s.size(); i++)
        {
            int c=s[i]-'a';
            if(c<0)
                cnt++;
           
        }
        int flag=0;
        if(a<0)
        {
            flag=1;
            cnt++;
        }
        if(cnt==s.size()||( flag &&cnt==1) ||!cnt)
            return true;
        return false;
    }
    bool detectCapitalUse(string word) {
        return isvalid(word);
    }
};