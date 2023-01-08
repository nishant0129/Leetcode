class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int cnt=1,res=0;
        for(int i=0; i<points.size(); i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1; j<points.size(); j++)
            {
              int x2=points[j][0];
              int y2=points[j][1];
                cnt=2;
                for(int k=j+1; k<points.size(); k++)
                {
                   int x3=points[k][0];
                   int y3=points[k][1];
                    
                    // int s1=(double)(y2-y1)/(double)(x2-x1);
                    // int s2=(double)(y3-y2)/(double)(x3-x2);
                    
                    if(((y2-y1)*(x3-x2))==((y3-y2)*(x2-x1)))
                        cnt++;
                }
                res=max(cnt,res);
            }
            res=max(cnt,res);
        }
        return res;
    }
};