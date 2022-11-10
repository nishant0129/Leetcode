//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void solve(long long int curr_no,long long int n,long long int & ans) {
      if(curr_no>n) {
          return ;
      }
      ans=max(ans,curr_no);
      int last_digit=curr_no%10;
      if(last_digit!=0 && last_digit!=9)
      {
          solve(curr_no*10+last_digit+1,n,ans);
          solve(curr_no*10+last_digit-1,n,ans);
          
      }
      else if(last_digit==0)
      {
          solve(curr_no*10+last_digit+1,n,ans);
      }
      else
          solve(curr_no*10+last_digit-1,n,ans);
      
  }
    long long jumpingNums(long long X) {
       string xstr=to_string(X);
       int first_digit=xstr[0]-'0';
       long long int ans=0;
      
       if(xstr.size()>=2 and xstr[0]=='1' and xstr[1]=='0') {
           solve(9,X,ans);
       }
       {
        solve(first_digit,X,ans);
        solve(first_digit-1,X,ans);
       }
       return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends