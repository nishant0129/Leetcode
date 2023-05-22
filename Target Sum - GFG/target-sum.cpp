//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
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
      int notake=solve(n,d,arr,idx+1,sum,tsum,dp);
      int take=solve(n,d,arr,idx+1,sum+arr[idx],tsum,dp);
      return dp[idx][sum]=(take+notake);
  }
   
    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
        int n=arr.size();
        int tsum=accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(tsum+1,-1));
        return solve(n,target,arr,0,0,tsum,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends