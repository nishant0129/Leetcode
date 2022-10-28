// class Solution {
// public:
//     // int rec(string s1,string s2,int m,int n,vector<vector<int>>&dp)
//     // {
//     //     if(n==0||m==0) return 0;
//     //     if(dp[m][n]!=-1) return dp[m][n];
//     //     if(s1[m-1]==s2[n-1]) 
//     //     {
//     //         return dp[m][n]=1+rec(s1,s2,m-1,n-1,dp);
//     //     }
//     //     else 
//     //     {
//     //         return dp[m][n]=max(rec(s1,s2,m,n-1,dp),rec(s1,s2,m-1,n,dp));
//     //     }
//     // }
//      int recur(int i,int j ,string &s1,string &s2, vector<vector<int>>&dp)
//     {
//         if(i < 0 || j < 0 ) 
//             return 0;
//             if(dp[i][j]!=-1)
//             return dp[i][j];
//         if(s1[i] == s2[j]) 
//         return dp[i][j]= 1+recur(i-1,j-1,s1,s2,dp);
        
//         return dp[i][j]= max(recur(i-1,j,s1,s2,dp),recur(i,j-1,s1,s2,dp));
        
//     }
  
//     int longestCommonSubsequence(string s1, string s2) {
//         int x=s1.size();
//         int y=s2.size();
//         vector<vector<int>>dp(x,vector<int>(y,-1));
//         return recur(x-1,y-1,s1,s2,dp);
//         // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         // return rec(s1,s2,m,n,dp);
//     }
// };

class Solution {
public:
    int rec(string &s1,string &s2,int m,int n,vector<vector<int>>&dp)
    {
        if(n==0||m==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m-1]==s2[n-1]) 
        {
            return dp[m][n]=1+rec(s1,s2,m-1,n-1,dp);
        }
        else 
        {
            return dp[m][n]=max(rec(s1,s2,m,n-1,dp),rec(s1,s2,m-1,n,dp));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return rec(s1,s2,m,n,dp);
    }
};