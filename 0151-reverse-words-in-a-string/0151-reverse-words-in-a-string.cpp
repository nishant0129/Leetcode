class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);
        string res="",word;
        while(ss>>word)
        {
            res=word+" "+res;
        }
        res.pop_back();
        return res;
    }
};