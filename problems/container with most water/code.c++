class Solution {
public:
  int maxArea(vector<int> &height)
  {
      int maxim=0;
    int l=0,r=height.size()-1;
      while(l<=r)
      { 
          int wid=r-l;
         int len= min(height[l],height[r]);
         int area=len*wid;
          maxim=max(area,maxim);
          if(height[l]>height[r])
          {
              r--;
          }
          else if(height[r]>height[l])
              l++;
          else{
              r--;
              l++;
          }
      }
      return maxim;
  }
};