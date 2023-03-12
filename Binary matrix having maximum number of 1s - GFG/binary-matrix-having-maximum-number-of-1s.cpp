//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        vector<int>v(2,0);
        int res=0;
        for(int i=0; i<mat.size(); i++)
        {
            int l=0,h=mat[i].size()-1;
            int cans=0;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(mat[i][mid]==1)
                {
                    h=mid-1;
                    cans=N-mid;
                    
                }
                else
                {
                    l=mid+1;
                }
            }
           // cout<<res<<" "<<cans<<endl;
            if(res<cans)
            {
                v[0]=i;
                v[1]=cans;
                res=cans;
                //cout<<1<<endl;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends