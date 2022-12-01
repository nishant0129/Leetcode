class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        int v1=0,v2=0;
        for(int i=0;i<s.size();i++)
        {
            if(i<s.size()/2)
            if(st.find(s[i])!=st.end())
                v1++;
            if(i>=s.size()/2)
               if(st.find(s[i])!=st.end())
                v2++; 
        }
        return v1==v2;
    }
};