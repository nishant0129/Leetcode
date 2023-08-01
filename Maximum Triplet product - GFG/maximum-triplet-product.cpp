//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	long long maxi1=INT_MIN,maxi2=INT_MIN,maxi3=INT_MIN,mini1=INT_MAX,mini2=INT_MAX;
    	for(int i=0; i<n; i++){
    	    if(arr[i]>maxi1){
    	        maxi3=maxi2;
    	        maxi2=maxi1;
    	        maxi1=(maxi1,arr[i]);}
    	        else if(arr[i]>maxi2){
    	            maxi3=maxi2;
    	            maxi2=arr[i];
    	        }
    	        else if(arr[i]>maxi3){
    	            maxi3=arr[i];
    	        }
    	    if(mini1>arr[i]){
    	        mini2=mini1;
    	        mini1=arr[i];
    	    }
    	    else if(mini2>arr[i]){
    	        mini2=arr[i];
    	    }
    	 
    	}
        return max(mini1*mini2*maxi1, maxi1*maxi2*maxi3);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends