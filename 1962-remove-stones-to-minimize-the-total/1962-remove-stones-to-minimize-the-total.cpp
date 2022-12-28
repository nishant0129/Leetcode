class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0; i<piles.size(); i++)
            pq.push(piles[i]);
        
        while(!pq.empty()&&k>0)
        {
           int top=pq.top();
            top=(int)ceil((double)top/2.0);
            pq.pop();
            pq.push(top);
            k--;
            
        }
        int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};