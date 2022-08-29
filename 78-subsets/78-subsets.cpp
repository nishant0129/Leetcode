class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>res;
        ans.push_back({});
        for(int i=0; i<nums.size(); i++)
        {
            int n=ans.size();
            for(int j=0; j<n; j++)
            {
                vector<int>v=ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};


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
//               if(i& (1<<j))
//                     v.push_back(nums[j]) ;
                 
//             }
//                   ans.push_back(v);
//         }
//                  return ans;
//    }
// };

