//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    int mod=1e9+7,zero;
    
	public:
	 
    long long int dfs(int curr_ind,int curr_sum,int sum,int n,int nums[],
                    vector<vector<long long int>>&dp) {
            
            if(curr_sum>sum) return 0;
            
	       if(curr_ind == n)
	       {

               if(curr_sum == sum)
               return 1;
           
               return 0;
           }
          if(dp[curr_ind][curr_sum]!=-1)
          return dp[curr_ind][curr_sum];
	    long long int not_take=dfs(curr_ind+1,curr_sum,sum,n,nums,dp);
	    long long int take=dfs(curr_ind+1,curr_sum+nums[curr_ind],sum,n,nums,dp);
	    
	    return dp[curr_ind][curr_sum]=(take+not_take)%mod;
	    
	    
	}
	
	
	int perfectSum(int nums[], int n, int sum)
	{
        vector<vector<long long int>>dp(n+1,vector<long long int>(sum+1,-1));
        // sort(nums,nums+n);
        // zero=1<<count(nums,nums+n,0);
        // // cout<<zero<<endl;
        // for(int i=0;i<=n;i++) {
        //     for(int j=0;j<=sum;j++) {
        //         if(j==0) dp[i][j]=(1<<zero);
        //         else if(i==0) dp[i][j]=0ll;
        //         else if (nums[i-1]==0 or j-nums[i-1]<0) dp[i][j]=dp[i-1][j]%mod;
        //         else dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i-1]])%mod;
        //     }
        // }
        // return dp[n][sum]%mod;
        return dfs(0,0,sum,n,nums,dp)%mod;
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