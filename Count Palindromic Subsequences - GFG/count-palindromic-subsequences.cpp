//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long n;
    long long mod=1000000007;
    long long int recur(string &a,int i,int j,vector<vector<long long>>&dp) {
        if(i>j) {
            return 0;
        }
        if(i==j) {
            return 1;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        if(a[i]==a[j]) {
            return dp[i][j]=(1+recur(a,i,j-1,dp)+recur(a,i+1,j,dp))%mod;
        }
        return dp[i][j]=(mod+recur(a,i,j-1,dp)+recur(a,i+1,j,dp)-recur(a,i+1,j-1,dp))%mod;
    }
    long long int  countPS(string str)
    {
        n=str.size();
        vector<vector<long long>>dp(n,vector<long long>(n,-1));
        return recur(str,0,n-1,dp)%mod;
        
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends