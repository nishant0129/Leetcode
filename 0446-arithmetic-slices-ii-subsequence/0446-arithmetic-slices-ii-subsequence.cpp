
// class Solution {
// public:
//     int n;
//     int ans;
//     void dfs(int j, vector<int>& nums, vector<long long > cur) {
//         if (j == n)
//         {
//             if (cur.size() < 3) 
//             {
//                 return;
//             }
//             for (int i = 1; i < cur.size(); i++) 
//             {
//                 if (cur[i] - cur[i - 1] != cur[1] - cur[0]) {
//                     return;
//                 }
//             }
//             ans ++;
//             return;
//         }
//         dfs(j + 1, nums, cur);
//         cur.push_back(nums[j]);
//         dfs(j + 1, nums, cur);
//     }
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         n = nums.size();
//         ans = 0;
        
//         vector<long long > cur;
//         dfs(0, nums, cur);
//         return (int)ans;
//     }
// };

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector< unordered_map<long, long> > dp(nums.size());
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - (long)nums[j];
                
                dp[i][diff]++;
                
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        
        return res;
    }
};