//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int target) 
	{ 
	    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
	    for(int j=0;j<target+1;j++)
	    {
	        dp[0][j]=1e9;
	    }
	    for(int j=1;j<target+1;j++)
	    {
	        if(j%coins[0]==0)
	        dp[1][j]=j/coins[0];
	        else 
	        dp[1][j]=1e9;
	    }
	    for(int i=2;i<n+1;i++)
	    {
	        for(int j=1;j<target+1;j++)
	        {
	            if(coins[i-1]<=j)
	            {
	                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	            }
	            else 
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	    return dp[n][target]>=1e9?-1:dp[n][target];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends