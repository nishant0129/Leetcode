//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>curr={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>v;
        for(int i=curr.size()-1; i>=0; i--)
        {
            if(curr[i]<=N)
            {
                int x=N/curr[i];
                 N-=curr[i]*x;
                while(x--)
                {
                    v.push_back(curr[i]);
                }
               
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends