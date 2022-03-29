class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> v, ans;
        set<vector<int>> s;
        if (nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int l = 1 + i, h = nums.size() - 1, sum = 0;
            while (l < h)
            {
                sum = nums[i] + nums[l] + nums[h];
                if (sum == 0)
                {
                    s.insert({nums[i], nums[l], nums[h]});
                    l++;
                    h--;
                }
                else if (sum > 0)
                    h--;
                else
                    l++;
            }
        }

        for (auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};