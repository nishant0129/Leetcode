class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
       unordered_map<char, int> mp1, mp2;
       
        for(int i = 0; i < magazine.length(); ++i)
            mp2[magazine[i]]++;
       
        for(auto ch : ransomNote)
        { 
            mp1[ch]++;
            if(mp1[ch] > mp2[ch]) 
                return false; 
        }
        return true;
    }
};