class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++) {
            if(not dq.empty() and dq.front()<=i-k) {
                dq.pop_front();
            }
            while(not dq.empty() and nums[i]>nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i+1>=k) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};