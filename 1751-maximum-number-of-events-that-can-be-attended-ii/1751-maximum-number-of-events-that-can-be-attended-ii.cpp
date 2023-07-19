class Solution {
public:
     int binary_search(int last,vector<vector<int>>& events)
     {
         int l=0,h=events.size()-1;
         int ans=-1;
         while(l<=h)
         {
             int mid=(l+h)/2;
             if(last<events[mid][0])
             {
                 ans=mid;
                 h=mid-1;
             }
             else
             l=mid+1;
         }
         return ans;
     }
    int solve(int idx,vector<vector<int>>& events, int k,vector<vector<int>>&dp)
    {
        if(idx==events.size() || k<=0)
        return 0;

        if(dp[idx][k]!=-1) return dp[idx][k];

        int notake=solve(idx+1,events,k,dp),take=events[idx][2];
        
        int lb=binary_search(events[idx][1],events);
        if(lb!=-1 && lb>idx )
        take+=solve(lb,events,k-1,dp);
        return dp[idx][k]=max(take,notake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
       sort(events.begin(),events.end()) ;
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
       return solve(0,events,k,dp);
    }
};