class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        vector<int>v(26,0),v1(26,0);
        for(int i=0; i<p.size(); i++)
            v[p[i]-'a']++;
        int i=0,j=0;
        while(j<p.size())
        {
            v1[s[j]-'a']++;
            j++;
        }
        vector<int>ans;
        if(v==v1)
        {  ans.push_back(i);
          
        }
        //j--;
        while(j<s.size())
        {
            v1[s[i]-'a']--;
            v1[s[j]-'a']++;
            i++;
            j++;
            if(v==v1)
                ans.push_back(i);
            
        }
        return ans;
    }
};