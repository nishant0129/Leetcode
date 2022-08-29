// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums)
//     {
//         vector<vector<int>>ans;
//         vector<int>res;
//         ans.push_back({});
//         for(int i=0; i<nums.size(); i++)
//         {
//             int n=ans.size();
//             for(int j=0; j<n; j++)
//             {
//                 vector<int>v=ans[j];
//                 v.push_back(nums[i]);
//                 ans.push_back(v);
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums)
//     {
//         int n=1<<nums.size();
//         vector<vector<int>>ans;
//         for(int i=0; i<n; i++)
//         {
//               vector<int>v;
//             for(int j=0; j<nums.size(); j++)
//             {
//                    if(i& (1<<j))
//                     v.push_back(nums[j]) ;
                 
//             }
//                   ans.push_back(v);
//         }
//                  return ans;
//    }
// };

class Solution {
public:
    void solve(vector<int>&nums,int i,vector<int>out,vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            ans.push_back(out);
            return;
        }
        solve(nums,i+1,out,ans);
        out.push_back(nums[i]);
        solve(nums,i+1,out,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int>out;
        vector<vector<int>>ans;
        solve(nums,0,out,ans);
        return ans;
    }
};


