//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    
	int recur(int coins[],int n,int target,int i,int csum,vector<vector<int>>&dp)
	{
	    if(csum==target)
	    return 0;
	    if(i>=n || csum>target)
	    return 1e6;
	   if(dp[i][csum]!=-1) return dp[i][csum];
	   // int take=0,nottake=0;
	    if(target>=csum+coins[i]) //pick or not pick 
	    {
	        return dp[i][csum]=min(1+recur(coins,n,target,i,csum+coins[i],dp),
	        recur(coins,n,target,i+1,csum,dp));
	       //csum+=coins[i];
	       //take=1+recur(coins,n,target,i+1,csum);
	    }
	    else
	   //  nottake=recur(coins,n,target,i+1,csum);
	    return dp[i][csum]=recur(coins,n,target,i+1,csum,dp);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    int ans= recur(coins,M,V,0,0,dp);
	    if(ans>=1e6) return -1;
	    else return ans;
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