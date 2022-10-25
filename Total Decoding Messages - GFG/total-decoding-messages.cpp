//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	 int mod=1000000007;
	    int recur(string str,int i,vector<int>&dp)
	    {
	        if(i==str.size())
	        {
	            return 1;
	        }
	        if(str[i]=='0')return 0;
	        if(dp[i]!=-1)
	        return dp[i];
	        int single= recur(str,i+1,dp);
	        int db=0;
	        if(i<str.size()-1)
	        {
	           int c=stoi(str.substr(i,2));
	           if(c>=1&&c<=26)
	           db=recur(str,i+2,dp);
	        }
	        
	        return dp[i]=( single%mod+db%mod)%mod;
	        
	    }
		int CountWays(string str){
		    // Code here
		    string s="";
		    int n=str.size();
		    vector<int>dp(n+1,-1);
		    return recur(str,0,dp);
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends