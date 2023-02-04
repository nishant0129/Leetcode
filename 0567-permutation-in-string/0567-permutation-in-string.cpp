class Solution {
public:
    bool checkInclusion(string s1, string s) {
        int n=s1.length(),m=s.length();
        if(n>m)return false;
        vector<int>v(26,0),v1(26,0);
       
        for(int i=0; i<n; i++)
             v[s1[i]-'a']++;
        
         int i=0,j=0;
        while(i<n)
        {
           v1[s[i]-'a']++;
            i++;
        }
        if(v==v1)
            return true;
        while(i<m)
        {
            v1[s[i]-'a']++;
             v1[s[j]-'a']--;
            i++;
            j++;
            if(v==v1)return true;
        }
        return false;
    }
};