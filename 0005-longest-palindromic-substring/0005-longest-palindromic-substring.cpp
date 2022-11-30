class Solution {
public:
    int expand_palindrome(int left,int right,int curr_len,string& s,int n) {
        while(left>=0 and right<n) {
            if(s[left--]==s[right++]) {
                curr_len+=2;
            }else {
                break;
            }
        }
        return curr_len;
    }
    
    string longestPalindrome(string s) {
        int n=s.size(),max_size=INT_MIN,start;
        for(int i=0;i<n;i++) {
            int curr_len=expand_palindrome(i-1,i+1,1,s,n);
            if(max_size<curr_len) {
                max_size=curr_len;
                start=i-(curr_len-1)/2;
            }
            if(i<n-1 and s[i]==s[i+1]) {
                int curr_len=expand_palindrome(i-1,i+2,2,s,n);
                if(max_size<curr_len) {
                    max_size=curr_len;
                    start=i-(curr_len-2)/2;
                }
            }
        }
        return s.substr(start,max_size);
    }
};