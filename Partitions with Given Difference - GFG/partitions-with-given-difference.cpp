//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
  int solve(int n,int d,vector<int>&arr,int idx,int sum,int tsum,vector<vector<int>>&dp)
  {
     
      if(idx==n)
      {
           if(tsum-2*sum==d)
            return 1;
            return 0;
      }
      if(dp[idx][sum]!=-1)
      return dp[idx][sum];
      int notake=solve(n,d,arr,idx+1,sum,tsum,dp)%mod;
      int take=solve(n,d,arr,idx+1,sum+arr[idx],tsum,dp)%mod;
      return dp[idx][sum]=(take+notake)%mod;
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int tsum=accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(tsum+1,-1));
        return solve(n,d,arr,0,0,tsum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends