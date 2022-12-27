//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
    stack<int>s;
    vector<int>ans;
    // ans.push_back(-1);
    // s.push(0);
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>=arr[i])
        s.pop();
        int a=s.empty()?-1:arr[s.top()];
        s.push(i);
        ans.push_back(a);
    }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends