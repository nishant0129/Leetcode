class Solution {
public:
    bool isvowel(char ch)
    {
         string str="aeiouAEIOU";
        if(str.find(ch)!=string::npos)
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(isvowel(s[i]) && isvowel(s[j]))
             {   
                swap(s[i],s[j]);
                i++;
                j--;
             }
            else if(isvowel(s[i]))
                j--;
            else
                i++;
        }
        return s;
    }
};