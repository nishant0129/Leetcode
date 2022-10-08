class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int MINI=INT_MAX,res=0;
        sort(nums.begin(),nums.end());
      for(int i=0; i<nums.size()-2; i++)  
      {
          int l=i+1,r=nums.size()-1;
          while(l<r)
          {
              int csum=nums[i]+nums[l]+nums[r];
              if(csum==target)
                  return csum;
              if(abs(csum-target)<MINI)
              {
                  MINI=abs(csum-target);
                  res=csum;
              }
               (csum > target) ? r-- : l++;
          }
      }
        return res;
    }
};