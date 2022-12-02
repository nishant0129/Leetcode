class Solution {
public:
    bool closeStrings(string word1, string word2) {
         unordered_map<int,int>mp1,mp2;
        set<char>s1,s2;
        for(auto i: word1)
        {
            mp1[i]++;
            s1.insert(i);
        }
        for(auto j:word2)
        {
            mp2[j]++;
            s2.insert(j);
        }
        if(s1!=s2)
            return false;
        multiset<int>s;
        for(auto i:mp1)
            s.insert(i.second);
        for(auto j:mp2)
            if(s.find(j.second)!=s.end())
            s.erase(s.find(j.second));
            else
                return false;
        if(s.size()==0)
            return true;
        return false;
    }
};