class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
      int i=0,j=p.size()-1,k=0,cnt=0,sum=0;
        sort(p.begin(),p.end());
      //  vector<int>v;
        while(i<=j)
        {  
            sum=p[i]+p[j];
            if(sum<=limit)
            {
                i++;
                j--;
            }
            
             else
             {
                 j--;
             }
            cnt++;
            
        }
        return cnt;
        
    }
};