// class Solution {
// public:
//     int n;
//     int dp[100002][2][2];
//     int solve(vector<int>& prices,int i,int hold,int k){
//         if(i>=n || k==0)
//             return 0;
//         int& ans=dp[i][hold][k];
//         if(ans!=-1)
//             return ans;
//         if(hold==1){
//             ans=max(solve(prices,i+1,1,k),solve(prices,i+1,0,k-1)+prices[i]);
//         }
//         else{
//             ans=max(solve(prices,i+1,0,k),solve(prices,i+1,1,k)-prices[i]);
//         }
//         return ans;
//     }
//     int maxProfit(vector<int>& prices) {
//         n=prices.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(prices,0,0,2);
//     }
// };

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>left_part(n,0);
        vector<int>right_part(n,0);
        int mini=prices[0];
        int maxi=prices[n-1];
        int profit_left=0;
        int profit_right=0;
        // int ans=0,buy=0,tprofit=0;
        for(int i=0;i<n;i++) {
            mini=min(mini,prices[i]);
            profit_left=max(profit_left,prices[i]-mini);
            left_part[i]=profit_left;
            maxi=max(maxi,prices[n-i-1]);
            profit_right=max(profit_right,maxi-prices[n-i-1]);    
            right_part[n-i-1]=profit_right;
            // buy=min(buy,profit_left-prices[i]);
            // tprofit=max(tprofit,prices[i]+buy);
        }
        int ans=right_part[0];
        for(int i=1;i<n;i++) {
            ans=max(ans,left_part[i-1]+right_part[i]);
        }
        // return tprofit;
        return ans;
    }
};
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};