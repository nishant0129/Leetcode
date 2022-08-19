class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // priority_queue<int>pq;
        // //    sort(stones.begin(),stones.end(),greater<int>());
        // for(int i=0; i<stones.size(); i++)
        // {
        //     pq.push(stones[i]);
        // }
        // int a=0;
        // while(pq.size()>1)
        // {
        //         a =pq.top();
        //        pq.pop();
        //     int b=pq.top();
        //     pq.pop();
        //     if(a>b)
        //         pq.push(a-b);
        //     if(a==b)
        //         pq.push(0);
        // }
        // int ans=pq.top();
        // return ans;
         priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1)
        {
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x!=y) pq.push(y-x);
        }
        return pq.empty()? 0 : pq.top();
    }
};