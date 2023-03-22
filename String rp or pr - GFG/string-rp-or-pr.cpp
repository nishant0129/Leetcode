//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    void fun(string &s)
    {
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='p')
            s[i]='r';
            else if(s[i]=='r')
            s[i]='p';
        }
    }
    long long solve(int X,int Y,string s){
      //code here
      if(Y>X)
      {
          fun(s);
          swap(X,Y);
      }
     // cout<<s<<endl;
      stack<char>st;
      long long int ans=0;
      int cp=0,cr=0;
      for(int i=0; i<s.size(); i++)
      {
          if(s[i]=='p')
          st.push(s[i]);
          else if(s[i]=='r')
          {
              if(st.empty())
              st.push(s[i]);
              else if(st.top()=='p')
              {
                  ans+=X;
                  st.pop();
              }
              else 
              {
                  st.push(s[i]);
              }
              
          }
          else
          {
              while(!st.empty())
              {
                  if(st.top()=='p')
                  {
                      cp++;
                      st.pop();
                  }
                  else if(st.top()=='r')
                  {
                      cr++;
                      st.pop();
                  }
                  else
                  {
                         while (!st.empty()) 
                                st.pop();
                            
                           break;
                  }
              }
              ans+=min(cp,cr)*Y;
              cp=0,cr=0;
          }
      }
      cp=0,cr=0;
              while(!st.empty())
              {
                  if(st.top()=='p')
                  {
                      cp++;
                      st.pop();
                  }
                  else if(st.top()=='r')
                  {
                      cr++;
                      st.pop();
                  }
                  else
                  break;
              }
            
              ans+=min(cp,cr)*Y;
              return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends