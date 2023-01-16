class Solution {
public:
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& na) {
    //    intervals.push_back(na);
    //     sort(intervals.begin(),intervals.end());
    //    vector<vector<int>>ans;
    //     ans.push_back(intervals[0]);
    //     for(int i=1; i<intervals.size(); i++)
    //     {
    //         if(ans.back()[1]>=intervals[i][0])
    //         {
    //             ans.back()[1]=max(intervals[i][1],ans.back()[1]);
    //         }
    //         else
    //         {
    //             ans.push_back(intervals[i]);
    //         }
    //     }
    //     return ans;
    // }
    
    
     vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& na) {
       vector<vector<int>>ans;
         int n=a.size();
       int i=0;
         while(i<n && a[i][1]<na[0])
         {
             ans.push_back(a[i]);
             i++;
         }
         while(i < n && na[1] >=a[i][0])
         {
            na[0] = min(na[0],a[i][0]);
            na[1] = max(na[1],a[i][1]);
             i++;
        }
         ans.push_back(na);
          while(i < n){
            ans.push_back(a[i]);
            i++;
        }
        return ans;
     }
};