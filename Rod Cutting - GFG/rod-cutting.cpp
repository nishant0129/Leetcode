//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
 int dp[1002][1002];
int solve(int price[],int n,int idx,int m)
{
    if(n==0 )
    {
        return 0;
    }
    if(n<0 || idx>=m)
    return -1e9;
    if(dp[n][idx]!=-1)
    return dp[n][idx];
    int nottake=solve(price,n,idx+1,m),take=0;
    if(n-idx-1>=0)
    {
        take=price[idx]+solve(price,n-idx-1,idx,m);
    }
    return dp[n][idx]=max(take,nottake);
}
    int cutRod(int price[], int n) {
        //code here
        memset(dp,-1,sizeof(dp));
        return solve(price,n,0,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends