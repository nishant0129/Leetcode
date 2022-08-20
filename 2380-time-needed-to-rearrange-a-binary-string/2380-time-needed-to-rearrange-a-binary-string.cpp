class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt,ans=0;
        while(true)
        {
            cnt=0;
            for(int i=0; i<s.size()-1; i++)
            {
               if(s[i]=='0'&& s[i+1]=='1')
               {
                   cnt++;
                   swap(s[i],s[i+1]);
                   i++;
               }
                
            }
            if(cnt>0)
            ans++;
            if(cnt==0)
                break;
        }
        return ans;
    }
};