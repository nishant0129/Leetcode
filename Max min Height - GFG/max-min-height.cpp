//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        bool check(long long int mid,vector<int>&a,int w,int k) {
            long long int n=a.size(),curr=0ll,days=0ll;
            vector<long long int>temp(n,0ll);
            
            for(int i=0;i<n;i++) {
                curr+=temp[i];
                if(mid>(curr+a[i])) {
                    long long int ct=mid-(curr+a[i]);
                    days+=ct;
                    curr+=ct;
                    if(i+w<=n-1) temp[i+w]-=ct;
                }
            }
            // cout<<mid<<" : "<<days<<endl;
            // if(mid==10) {
            //     for(auto i:temp) cout<<i<<" "<<endl;
            // }
            
            return days<=k;
        }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a) {
            long long int low=1,high=1e14,ans=-1;
            while(low<=high) {
                long long int mid=(low+high)>>1;
                if(check(mid,a,w,k)) {
                    // cout<<mid<<" ";
                    ans=mid;
                    low=mid+1;
                }else {
                    high=mid-1;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends