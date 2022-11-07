//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
         int recur(string &str,string &s,int i,int j,vector<vector<int>>&dp)
         {
             if(i==s.size()||j==s.size())
             return 0;
             if(dp[i][j]!=-1)
             return dp[i][j];
             if(str[i]==s[j] && i!=j)
             {
                 return dp[i][j]=1+recur(str,s,i+1,j+1,dp);
             }
             else
             return dp[i][j]=max(recur(str,s,i,j+1,dp),recur(str,s,i+1,j,dp));
         }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    vector<vector<int>>dp(n,vector<int>(n,-1));
		  return recur(str,str,0,0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends