//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int arr[], int n, int k) 
    { 
       int l=0,h=n-1;
      while(l<=h)
      {
          int mid=(l+h)/2;
          if(arr[mid]==k)
          return k;
          else if(k<arr[mid])
          h=mid-1;
          else
          l=mid+1;
      }
      int d1=0,d2=0;
      if(l>=0 && l<n)
          d1=abs(arr[l]-k);
      
      
     
      
      if(l-1>=0 && l-1<n)
          d2=abs(arr[l-1]-k);
    
      if(d1==0)
      return arr[l-1];
      if(d2==0)
      return arr[l];
      if(d1>d2)
      return arr[l-1];
      return arr[l];
    
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends