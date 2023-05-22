//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   bool solve(vector<int>&arr ,int sum,int idx, vector<vector<int>>&dp)
   {
       if(sum==0)
       return true;
       if(idx>=arr.size()||sum<0)
       return false;
       if(dp[idx][sum]!=-1)
       return dp[idx][sum];
       bool notake=solve(arr,sum,idx+1,dp);
       bool take=solve(arr,sum-arr[idx],idx+1,dp);
       return dp[idx][sum]=take||notake;
   }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
       return solve(arr,sum,0,dp);
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