//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int recur(int a[],int n,int i,int &ans,int csum,vector<int>&dp)
    {
        if(i>=n)
        {
            ans=max(ans,csum);
           return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int take=a[i] +recur(a,n,i+2,ans,a[i],dp);
        int nottake=recur(a,n,i+1,ans,csum,dp);
        return dp[i]=max(take,nottake);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int ans=0;
        vector<int>dp(n+1,-1);
        int csum=0;
        return recur(arr,n,0,ans,csum,dp);
        return ans;
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