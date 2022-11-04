//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int recur(vector<int>&arr,int target,int i,vector<vector<int>>&dp)
    {
        if(target==0)
        return 1;
        if(i==arr.size()||target<0)
        return 0;
        if(dp[i][target]!=-1)
        return dp[i][target];
        if(arr[i]<=target)
        {
            return dp[i][target]=recur(arr,target-arr[i],i+1,dp)||recur(arr,target,i+1,dp);
        }
        return dp[i][target]=recur(arr,target,i+1,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return recur(arr,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends