class Solution {
public:
    string getSmallestString(int n, int k) {
      map<int ,char>mp;
        int j=1;
        char c='a';
        for(int i=0; i<26; i++)
        {
             mp[i]=c;
            c++;
        }
        string ans="";
        k=k-(n);
        for(int i=0; i<n; i++)
        {
            ans+='a';
        }
        for(int i=n-1; i>=0; i--)
        {
            if(k>=25)
            {
                ans[i]=mp[25];
                k=k-25;
            }
                else
                {
                    ans[i]=mp[k];
                    break;
                }  
        }
        return ans;
    }
};