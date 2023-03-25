//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */


class Solution{
  public:
  int sum;
  bool ans=false;
    void subset_sum(int curr_index,int found,int curr_sum,vector<int>&arr,vector<bool>&visited){
        
        if(ans or found==0) {
            ans=true;
            return;
        }
        if(curr_sum==0) {
            subset_sum(0,found-1,sum,arr,visited);
        }
        if(curr_sum<0 or curr_index==arr.size()) return;
        
        if(curr_index==arr.size() or curr_sum<0) return ;
        subset_sum(curr_index+1,found,curr_sum,arr,visited);
        if(not visited[curr_index]) {
            curr_sum-=arr[curr_index];
            visited[curr_index]=true;
            subset_sum(curr_index+1,found,curr_sum,arr,visited);
            curr_sum+=arr[curr_index];
            visited[curr_index]=false;
        }
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
        vector<int>arr(a,a+n);
        sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%k!=0) return false;
        sum=sum/k;
        vector<bool>visited(n,false);
        subset_sum(0,k,0,arr,visited);
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
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends