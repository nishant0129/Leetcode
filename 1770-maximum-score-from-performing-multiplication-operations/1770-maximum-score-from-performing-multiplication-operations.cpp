class Solution {
public:
int recur(vector<int> &nums, vector<int> &multi, int i, int l,vector<vector<int>>&dp){
	if(i==multi.size())
		return 0;
    int r=nums.size()-(i-l)-1;
    if(dp[i][l]!=INT_MAX) {
        return dp[i][l];
    }
	return dp[i][l]=max(multi[i]*nums[l] + recur(nums, multi, i+1, l+1,dp), multi[i]*nums[r] + recur(nums, multi, i+1, l,dp));
}

int maximumScore(vector<int>& nums, vector<int>& multi) {
    int m=multi.size();
    vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MAX));
	return recur(nums, multi, 0, 0,dp);
}
};