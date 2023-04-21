//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>nums, int sum){
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1));
        for(int i=0;i<=nums.size();i++) {
            for(int j=0;j<=sum;j++) {
                if(j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else if(j-nums[i-1]<0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][sum];
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