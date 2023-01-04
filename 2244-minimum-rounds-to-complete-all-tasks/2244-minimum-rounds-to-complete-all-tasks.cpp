class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto i:tasks)
        {
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp)
        {
            int x=i.second/3;
            int rem=i.second%3;
            if(rem==2)
                ans+=x+1;
            if(rem==0)
                ans+=x;
            if(rem==1)
            {
                if(x==0)
                    return -1;
                x--;
                ans+=x+2;
            }
        }
       return ans;
    }
};