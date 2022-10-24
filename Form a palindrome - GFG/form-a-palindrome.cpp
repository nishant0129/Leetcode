//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
   int largest_subsequence(string s1,string s2)
//   {
//       if(i>=s1.size() ||j>=s2.size())
//       return 0;
//       if(dp[i][j]!=-1)
//       return dp[i][j];
//       if(s1[i]==s2[j])
//       {
//           return dp[i][j]= 1+recur(s1,s2,i+1,j+1,dp);
//       }
//       return dp[i][j]=max(recur(s1,s2,i+1,j,dp),recur(s1,s2,i,j+1,dp));
//   }
    {
        int n=s1.size(),ans=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                ans=max(dp[i][j],ans);
            }
        }
        return ans;
    }
    int countMin(string str){
     int n=str.size();
    string s1=str,s2=str;
    reverse(s2.begin(),s2.end());
    int lp=largest_subsequence(s1,s2);
    return n-lp;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends