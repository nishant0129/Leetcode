class Solution {
public:
    int expand_palindrome(int left,int right,string& s,int n) {
        int ct=0;
        while(left>=0 and right<n) {
            if(s[left--]==s[right++]) {
                ct++;
            }else {
                break;
            }
        }
        return ct;
    }
    
    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++) {
            ans+=expand_palindrome(i,i+1,s,n)+expand_palindrome(i,i,s,n);
        }
        return ans;
    }
};