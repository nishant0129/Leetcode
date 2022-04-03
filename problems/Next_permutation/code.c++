class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int l,r;
        for(l=n-2;l>=0;l--)                           // find incresing sequence
        {
            if(nums[l]<nums[l+1]) break;
        }
        if(l<0) reverse(nums.begin(),nums.end());
        else
        {
            for(r=n-1;r>l;r--)                       // find pivot
            {
                if(nums[r]>nums[l]) break;
            }
            swap(nums[l],nums[r]);                  // swap l,r
            
            reverse(nums.begin()+l+1,nums.end());   // reverse from l+1 to end
        }
    
//      void nextPermutation(vector<int>& nums)
//      {
//         int size=nums.size();
//         int i=size-2;
//         for(;  i>=0 && nums[i]>=nums[i+1]; --i) ;
        
//         int j=i+1;
//         int k=size-1;
//         while(j<k)
//         {
//             swap(nums[j],nums[k]);
//             ++j;
//             --k;
//         }
        
//         if(i==-1)
//             return;
        
//         for(j=i+1;j<size;++j)
//         {
//             if(nums[j]>nums[i])
//             {
//                 swap(nums[i],nums[j]);
//                 break;
//             }
//         }
         /*
      next_permutation(nums.begin(),nums.end()); */
    }
    
  
};