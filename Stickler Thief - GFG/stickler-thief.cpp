//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
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
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends