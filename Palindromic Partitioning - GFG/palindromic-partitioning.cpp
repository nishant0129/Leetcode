//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool is_palindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &str,int idx,int n,vector<int>&dp)
    {
        if(idx>=str.size())
        return 0;
        if(is_palindrome(str,idx,n))
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        int ans=INT_MAX;
        for(int i=idx; i<n; i++)
        {
            if((is_palindrome(str,idx,i)))
            {
                int tmp=1+solve(str,i+1,n,dp);
                ans=min(ans,tmp);
            }
        }
        return dp[idx]=ans;
    }
    
    int palindromicPartition(string str)
    { 
        vector<int>dp(str.size()+1,-1);
        return solve(str,0,str.size()-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends