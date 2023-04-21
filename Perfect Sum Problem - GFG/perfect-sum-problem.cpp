//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod=1e9+7;
	public:
	int perfectSum(int nums[], int n, int sum)
	{
        vector<vector<long long int>>dp(n+1,vector<long long int>(sum+1));
        int zero=count(nums,nums+n,0);
        // cout<<zero<<endl;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=sum;j++) {
                if(j==0) dp[i][j]=(1<<zero);
                else if(i==0) dp[i][j]=0ll;
                else if (nums[i-1]==0 or j-nums[i-1]<0) dp[i][j]=dp[i-1][j]%mod;
                else dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i-1]])%mod;
            }
        }
        return dp[n][sum]%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends