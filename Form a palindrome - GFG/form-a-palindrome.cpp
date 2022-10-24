//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
   int recur(string s1,string s2,int i,int j,vector<vector<int>>&dp)
   {
       if(i>=s1.size() ||j>=s2.size())
       return 0;
       if(dp[i][j]!=-1)
       return dp[i][j];
       if(s1[i]==s2[j])
       {
           return dp[i][j]= 1+recur(s1,s2,i+1,j+1,dp);
       }
       return dp[i][j]=max(recur(s1,s2,i+1,j,dp),recur(s1,s2,i,j+1,dp));
   }
    int countMin(string str){
    //complete the function here
      int n=str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    string s1=str,s2=str;
    reverse(s2.begin(),s2.end());
     int lp=recur(s1,s2,0,0,dp);
   
     return n-lp;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends