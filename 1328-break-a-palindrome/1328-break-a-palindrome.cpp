class Solution {
public:
    string breakPalindrome(string palindrome) {
        unordered_map<char,int>mp;
        for(auto i:palindrome)
        {
            mp[i]++;
        }
       
        for(int i=0; i<palindrome.size()/2; i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                return  palindrome;
            }
        }
         if(palindrome.size()==1 )
                return "";
            else
            {
                palindrome[palindrome.size()-1]='b';
                return palindrome;
            }
    }
};