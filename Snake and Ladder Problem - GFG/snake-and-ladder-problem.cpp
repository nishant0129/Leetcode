//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        //unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int i=0; i<2*N; i+=2)
        {
           // st.insert(arr[i]);
            mp[arr[i]]=arr[i+1];
        }
        queue<int>q;
        q.push(1);
        int cdis=0;
        vector<int>vis(31,0);
        while(!q.empty())
        {
            int sz=q.size();
            
            while(sz--)
            {
              int cur=q.front();
              if(cur>=30)
              return cdis;
              q.pop();
              for(int i=1;i<=6; i++)
              {
                 
                      if(mp.find(cur+i)!=mp.end())
                          q.push(mp[cur+i]);
                      else
                          q.push(cur+i);
                    
              }
            }
            cdis++;
        }
        return cdis;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends