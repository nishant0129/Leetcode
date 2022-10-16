class Solution {
public:
    
    int solve(vector<int>&arr, int idx, int d, vector<vector<int>>&dp){
        
        if(idx >= arr.size())
            return 1e7;
        if(d == 1)
        {
          int temp=*max_element(arr.begin()+idx,arr.end());
            return temp;
        }
        if(dp[idx][d]!=-1)
            return dp[idx][d];
        
        int res = INT_MAX;
        int curr = 0;
        
        for(int i=idx;i<arr.size();i++)
        {
            curr = max(curr, arr[i]);
            res = min(res, curr + solve(arr, i+1, d-1, dp));
        }
        return dp[idx][d] = res;
    }
    
    int minDifficulty(vector<int>& arr, int d)
    {
        if(arr.size() < d)
            return -1;
        vector<vector<int>>dp(arr.size(), vector<int>(d+1, -1));
        int res = solve(arr, 0, d, dp);
        return res;
    }
};