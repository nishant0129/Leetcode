class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int c=0,reach=0,res=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            c=max(c,nums[i]+i); 
            if(i==reach)
            {
                reach=c;
                res++;
            }
        }
        return res;
    }
};