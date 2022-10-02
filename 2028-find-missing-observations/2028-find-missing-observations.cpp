class Solution {
public:
//     void recur(int mean,int n,int target,vector<int>&v,vector<int>&ans)
//     {
        
//         if(n<0||target<0)
//             return  ;
//         if(n==0 && target==0)
//         {  
//             ans=v;
           
//             return ;
//         }
//         for(int i=1; i<7; i++)
//         {
//             v.push_back(i);
//             recur(mean,n-1,target-i,v,ans);
//             v.pop_back();
//         }
        
        
//     }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int sum=(n+rolls.size())*mean-accumulate(rolls.begin(),rolls.end(),0);
    
        if(sum<=0)
            return {};
        vector<int>v,ans;
      //  cout<<"sum="<<sum<<endl;
        int k=sum/n;
        if(k>6)
        {
            return {};
        }
      //  cout<<"k="<<k<<endl;
        int left_sum=sum-k*(n);
       // cout<<"left="<<left_sum<<endl;
     
            ans.assign(n,k);
                int i=0;
                while(i<ans.size() && left_sum--)
                {
                    ans[i]+=1;
                    i++;
                }
           // cout<<"leftt"<< left_sum<<endl;
                if(left_sum==-1)
                {
                    if(ans[0]>6 || ans[ans.size()-1]<1)
                        return {};
                    else
                        return ans;
                }
                else
                return {};
    }
};