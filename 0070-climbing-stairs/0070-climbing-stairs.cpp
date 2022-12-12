class Solution {
public:
 int climbStairs(int n) 
{
     vector<int> step(n,0);
     step[0]=1;
     if(n>=2)
     step[1]=2;
     for(int i=2;i<n;i++)
     {
         step[i]=step[i-2]+step[i-1];
     }
     return step[n-1];
 }};