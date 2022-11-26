class Solution {
public:
    int findNext(vector<vector<int>>&jobs, int curr){
        
        int low = curr+1, high = jobs.size()-1, ans = -1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(jobs[mid][0]>=jobs[curr][1]){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
    
    int solve(int curr, vector<vector<int>>&jobs, vector<int>&dp){
        if(curr == jobs.size() || curr == -1)return 0;
        
        if(dp[curr]!=-1)return dp[curr];
        
        int next = findNext(jobs,curr);
        
        int pick = jobs[curr][2] + solve(next,jobs,dp);
        
        int notPick = solve(curr+1,jobs,dp);
        
        return dp[curr] = max(pick,notPick);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs;
        vector<int>dp(n+1,-1);
        
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(jobs.begin(),jobs.end());
        return solve(0,jobs,dp);
    }
};