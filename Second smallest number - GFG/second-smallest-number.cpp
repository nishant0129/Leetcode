//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int sum, int D){
        // code here 
        if(9*D<=sum)
        return "-1";
       string s(D,'0');
        int idx=0;
        s[0]='1';
        sum--;
        for(int i=D-1; i>=0; i--)
        {
            if(sum>9)
            {
                s[i]='9';
                sum-=9;
            }
            else
            {
                if(i==0)
                {
                    s[i]=((sum+1)+'0');
                }
                else
                {
                    s[i]=(sum+'0');
                    
                }
                sum=0;
                break;
            }
        }
        if(sum>0)
        return "-1";
       // cout<<s<<endl;
       //s[D-1]--;
      int id=0;
      int f=0;
      for(int i=D-1; i>=0; i--)
      {
          while(i>=0 && s[i]=='9')
          {
              f=1;
              i--;
          }
          if(f)
          i++;
          s[i]--;
         // break;
          for(int j=i-1; j>=0; j--)
          {
              if(s[j]!='9')
              {
              s[j]++;
              return s;
              }
          }
       
          
      }
    //   s[id]--;
    //   sort(s.begin(),s.end());
    //     for(int i=s.size()-2; i>=0; i--)
    //     {
    //         if(s[i]<s[i+1])
    //         swap(s[i],s[i+1]);
    //     }
        //cout<<s<<endl;
         return s;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends