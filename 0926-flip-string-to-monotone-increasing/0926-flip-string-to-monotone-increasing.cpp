class Solution {
public:
    
    int minFlipsMonoIncr(string s) {
        vector<int>pref,suff;
        int cnt=0;
        
       for(int i=0; i<s.size(); i++)
       {
          if(s[i]=='1')
              cnt++;
           pref.push_back(cnt);
       }
        
          int ans=cnt;
        cnt=0;
        
       for(int i=s.size()-1; i>=0; i--)
       {
          if(s[i]=='0')
              cnt++;
           suff.push_back(cnt);
       }
        
        reverse(suff.begin(),suff.end());
      
       for(int i=0; i<s.size()-1; i++)
       {
          int o=pref[i];
          int z=suff[i+1];
          ans=min(ans,o+z);
          
       }
      
        return min(ans,cnt);
        
    }
};