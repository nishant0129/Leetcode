//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  vector<vector<int>> dp;
    int solve(int i, int cursum , int &totalSum , int arr[] , int n)
    {
        if(i == n)
            return abs(totalSum - 2*cursum);
        
        if(dp[i][cursum]!= -1)
         return dp[i][cursum];
        int op1 = solve(i + 1, cursum + arr[i], totalSum , arr , n);
        int op2 = solve(i + 1, cursum , totalSum , arr , n);
        return dp[i][cursum] = min(op1,op2);
    }
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i = 0; i < n; i++){
	       sum += arr[i];
	    }
	    dp.resize(n , vector<int>(sum, -1));
	    return solve(0,0,sum,arr,n);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends