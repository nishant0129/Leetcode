class Solution {
public:
//     void recur(vector<int>&v,vector<int>&nums,set<vector<int>>&s,vector<int>&vis)
//     {
//         if(v.size()==nums.size())
//         {
//             s.insert(v);
//             return;
//         }
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(!vis[i])
//             {
//               v.push_back(nums[i]);
//               vis[i]=1;
//               recur(v,nums,s,vis);
//               v.pop_back();
//               vis[i]=0;
//             }
            
            
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         set<vector<int>>s;
//         vector<vector<int>>ans;
//         vector<int>v,vis(nums.size(),0);
//        recur(v,nums,s,vis);
//         for(auto i:s)
//             ans.push_back(i);
//         return ans;
//     }
    
    

    void recur(vector<int>nums,int idx,vector<vector<int>>&ans)
    {
        if(idx>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
         for (int i = idx; i < nums.size(); i++) 
         {
                if (i == idx || nums[i] != nums[idx]) 
                {
                    swap(nums[idx], nums[i]);
                    recur(nums, idx + 1, ans);
                }
            }
    }
 vector<vector<int>> permuteUnique(vector<int>& nums) {
     
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        recur(nums,0,ans);
       
        return ans;
    }
};