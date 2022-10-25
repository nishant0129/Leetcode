//using deque;

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int>ans;
//         deque<int>dq;
//         for(int i=0;i<nums.size();i++) {
//             if(not dq.empty() and dq.front()<=i-k) {//when the element goes out of window ,remove the element
//                 dq.pop_front();
//             }
//             while(not dq.empty() and nums[i]>nums[dq.back()]) {// when the current element is greater than the elements at the back of deque , pop out all the elements from the back of deque so that elements remain in sorted order.
//                 dq.pop_back();
//             }
//             dq.push_back(i);//inserting indexes in deque so that the element can be removed when it's window is over
//             if(i+1>=k) {// when the window get full of size k push in the ans;
//                 ans.push_back(nums[dq.front()]);
//             }
//         }
//         return ans;
//     }
// };


//using priority_queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
       for(int i=0; i<k; i++)
       {
           pq.push({nums[i],i});
       }
        ans.push_back(pq.top().first);
        int n=nums.size();
        for(int i=k; i<n; i++)
        {
            pq.push({nums[i],i});
             while(!(pq.top().second > i-k))
                pq.pop();
            
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};