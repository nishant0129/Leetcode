class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int res=INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                
                if(nums1[i]==nums2[j])
                {
                   if(i==0||j==0)
                      dp[i][j]=1;
                    else
                      dp[i][j]=dp[i-1][j-1]+1;
                }
               
                res=max(res,dp[i][j]);
            }
        }
        if(res==INT_MIN)
            return 0;
        return res;
    }
};