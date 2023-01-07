class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>ans(gas.size(),0);
        int diff=0,tsum=0,csum=0,idx=0;
        for(int i=0; i<gas.size();i++)
        {
            diff = gas[i] - cost[i];

            tsum += diff;
            csum += diff;
            if(csum < 0)
            {
                idx= i+1;
                csum= 0;
            }
        }
        if(tsum>=0)
            return idx;
        return -1;
        
    }
};