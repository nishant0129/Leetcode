class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
       vector<int>diff;
        int n=rocks.size();
        for(int i=0; i<n; i++)
            diff.push_back(capacity[i]-rocks[i]);
        sort(diff.begin(),diff.end());
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(ar>=diff[i])
            {
                cnt++;
                ar-=diff[i];
            }
            else
                break;
        }
        return cnt;
    }
};