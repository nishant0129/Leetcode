class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) 
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(),points.end(),cmp);
        int a1=points[0][0],a2=points[0][1],cnt=0;
        for(int i=1; i<points.size();i++)
        {
            if(points[i][0]>a2)
            {
                cnt++;
                a2=points[i][1];
            }
        }
        return cnt+1;
    }
};