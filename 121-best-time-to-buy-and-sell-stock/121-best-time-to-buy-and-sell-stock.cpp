class Solution {
public:
    int maxProfit(vector<int>& stock) {
        int mini=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<stock.size()-1;i++)
        {
            mini=min(mini,stock[i]);
            if(stock[i+1]>stock[i])
            {
                maxprofit=max(maxprofit,stock[i+1]-mini);
            }
        }
        return maxprofit;
    }
};