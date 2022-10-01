// class Solution {
// public:
//   int solve(string s,int idx)
//     {
//         if(idx==s.size())
//             return 1;
//         if(s[idx]=='0')
//             return 0;
//         if(idx==s.size()-1)
//             return 1;
        
//         string temp=s.substr(idx,2);
//         int op1=solve(s,idx+1);
//         int op2=(stoi(temp)>=1 and stoi(temp)<=26)?solve(s,idx+2):0;
//         return op1+op2;
//     }
//     int numDecodings(string s) {
        
        
//         return solve(s,0);
//     }
// };

class Solution {
public:

    int solve(string s,int idx,vector<int>&dp)
    {
        if(idx==s.size())
            return 1;
        if(s[idx]=='0')
            return 0;
        if(idx==s.size()-1)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        string temp=s.substr(idx,2);
        
        int op1=solve(s,idx+1,dp);
        int op2=(stoi(temp)>=1 and stoi(temp)<=26)?solve(s,idx+2,dp):0;
        
        return dp[idx]=op1+op2;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
       // memset(dp,-1,sizeof dp);
        return solve(s,0,dp);
    }
};