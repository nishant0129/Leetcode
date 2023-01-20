class Solution {
public:
    void solve(vector<int>& nums,vector<int>&v,set<vector<int>>&st,int cnt)
      {
           if(cnt==nums.size())
           {
               if(v.size()>1) st.insert(v);
               // cout<<cnt<<" #";
               // for(auto i: v)
               //     cout<<i<<" ";
               //     cout<<endl;
                return;
               
           }
            
        if(v.empty()||nums[cnt]>=v.back())
        {
          //  cout<<nums[cnt]<<"  cnt"<<endl;
            v.push_back(nums[cnt]);
            solve(nums,v,st,cnt+1);
            v.pop_back();
        }
        solve(nums,v,st,cnt+1);
        return;
      }
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        set<vector<int>>st;
        vector<vector<int>>ans;
        vector<int>v;
        int n=nums.size();
        solve(nums,v,st,0);
        for(auto &i:st) 
            ans.push_back(i);
        return ans;
    }
};






// class Solution {
// public:
//     void solve(vector<int>& nums,vector<int>&v,set<vector<int>>&st,int idx,int n)
//           {
//                if(v.size()>1)
//                 {
//                    st.insert(v);
                   
//                 }
//               if(v.size()>n)
//                   return;
//               for(int i=idx; i<nums.size(); i++)
//               {
//                   if(v.empty() || v.back()<=nums[i])
//                   {
//                       v.push_back(nums[i]);
//                       solve(nums,v,st,i+1,n);
//                       v.pop_back();
                     
//                   }
//               }
//           }
//     vector<vector<int>> findSubsequences(vector<int>& nums)
//     {
//         set<vector<int>>st;
//         vector<vector<int>>ans;
//         vector<int>v;
//         int n=nums.size();
//         solve(nums,v,st,0,n);
//         for(auto &i:st) 
//             ans.push_back(i);
//         return ans;
//     }
// };