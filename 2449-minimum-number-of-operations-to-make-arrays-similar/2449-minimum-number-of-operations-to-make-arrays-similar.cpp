class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int>no,ne,to,te;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        for(auto i:nums)
        {
            if(i%2==0)
                ne.push_back(i);
            else
                no.push_back(i);
        }
        for(auto i:target)
        {
            if(i%2==0)
                te.push_back(i);
            else
                to.push_back(i);
        }
       long long  int sum=0;
        for(int i=0; i<ne.size();i++)
        {
            int x=te[i]-ne[i];
            if(x>0)
                sum+=x;
        }
        for(int i=0; i<no.size();i++)
        {
            int x=to[i]-no[i];
            if(x>0)
                sum+=x;
        }
        return sum/2;
    }
};