
//using 2d

// class Solution {
// public:
//     int solve(vector<int>&v,int idx,int alice,vector<vector<int>>&dp)
//     {
        
//         if(idx >= v.size())
//            return 0;
        
//         if(dp[idx][alice]!= -1)
//             return dp[idx][alice];
//          int sum=0;
//         if(alice)
//         {
//             int ans=INT_MIN;
//             for(int i=idx; i-idx<3 && i<v.size();i++)
//             {
//                 sum+=v[i];
//                 ans=max(ans,sum+solve(v,i+1,!alice,dp));
//             }
//             dp[idx][alice]=ans;
//         }
//         else
//         {
//             int ans=INT_MAX;
             
//             for(int i=idx; i-idx<3 && i<v.size();i++)
//             {
//                // sum+=v[i];
//                 ans=min(ans,solve(v,i+1,!alice,dp));
//             }
//             dp[idx][alice]=ans;
//         }
//         return dp[idx][alice];
        
//     }
//     string stoneGameIII(vector<int>& sv) {
//         //vector<vector<vector<int>>>dp(sv.size()+1,vector<vector<int>>(2,vector<int>(2,-1)));
//         vector<vector<int>>dp(sv.size()+1,vector<int>(2,-1));
//         int asum= solve(sv,0,1,dp);
//         int tsum=accumulate(sv.begin(),sv.end(),0);
//         int bsum=tsum-asum;
//        // cout<<asum<<" "<<bsum<<endl;
//         if(asum>bsum )
//             return "Alice";
//         else if(bsum>asum)
//             return "Bob";
//         else
//             return "Tie";
//     }
// };

class Solution {
public:
    int solve(vector<int>&v,int idx,int alice,int bob,vector<vector<vector<int>>>&dp)
    {
        
        if(idx >= v.size())
           return 0;
        
        if(dp[idx][alice][bob]!= -1)
            return dp[idx][alice][bob];
         int sum=0;
        if(alice)
        {
            int ans=INT_MIN;
            for(int i=idx; i-idx<3 && i<v.size();i++)
            {
                sum+=v[i];
                ans=max(ans,sum+solve(v,i+1,!alice,!bob,dp));
            }
            dp[idx][alice][bob]=ans;
        }
        if(bob)
        {
            int ans=INT_MAX;
             
            for(int i=idx; i-idx<3 && i<v.size();i++)
            {
               // sum+=v[i];
                ans=min(ans,solve(v,i+1,!alice,!bob,dp));
            }
            dp[idx][alice][bob]=ans;
        }
        return dp[idx][alice][bob];
        
    }
    string stoneGameIII(vector<int>& sv) {
        vector<vector<vector<int>>>dp(sv.size()+1,vector<vector<int>>(2,vector<int>(2,-1)));
        //vector<vector<int>>dp(sv.size()+1,vector<int>(2,-1));
        int asum= solve(sv,0,1,0,dp);
        int tsum=accumulate(sv.begin(),sv.end(),0);
        int bsum=tsum-asum;
       // cout<<asum<<" "<<bsum<<endl;
        if(asum>bsum )
            return "Alice";
        else if(bsum>asum)
            return "Bob";
        else
            return "Tie";
    }
};