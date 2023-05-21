//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int solve(int *arr,int n,int i,vector<int>&dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int notake=solve(arr,n,i+1,dp);
        int take=arr[i]+solve(arr,n,i+2,dp);
        return dp[i]=max(take,notake);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1)
	    return arr[0];
	    vector<int>dp(n,-1);
	    dp[n-1]=arr[n-1];
	    dp[n-2]=max(arr[n-1],arr[n-2]);
	    for(int i=n-3; i>=0; i--)
	    {
	        dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
	    }
	    return dp[0];
	   return solve(arr,n,0,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends