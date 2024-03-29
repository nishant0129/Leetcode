//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[105][105];
    int solve(int i,int j,int arr[]) {
        if(j-i<=1) return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)
        return dp[i][j];
        for(int k=i+1;k<j;k++) {
            mini = min(mini,arr[i]*arr[k]*arr[j]+solve(i,k,arr)+solve(k,j,arr));
        }
        return dp[i][j]=mini;
        
    }
    int matrixMultiplication(int N, int arr[])
    {
         memset(dp,0,sizeof(dp));
        // return solve(0,N-1,arr);
       
        for(int i=N; i>=0; i--)
        {
            for(int j=0; j<N; j++)
            {
                if(j-i<=1)
                {
                     dp[i][j]=0;
                     continue;
                }
                int mini=INT_MAX;
                for(int k=i+1;k<j;k++) {
                    mini = min(mini,arr[i]*arr[k]*arr[j]+dp[i][k]+dp[k][j]);
                }
                 dp[i][j]=mini;
                
            }
        }
       
        return dp[0][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends