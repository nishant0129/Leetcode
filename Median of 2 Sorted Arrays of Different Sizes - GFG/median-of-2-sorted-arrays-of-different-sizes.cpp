//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        int n1=arr1.size(),n2=arr2.size();
        if(n1>n2)
        {
            swap(arr1,arr2);
            swap(n1,n2);
        }
         
        int low=0,high=n1;
        while(low<=high)
        {
            double cut1=(low+high)/2;
            double cut2=(n1+n2)/2-cut1;
            double l1 = cut1 == 0? INT_MIN : arr1[cut1-1];
            double l2 = cut2 == 0? INT_MIN : arr2[cut2-1];
            double r1 = cut1 == n1? INT_MAX : arr1[cut1];
            double r2 = cut2 == n2? INT_MAX : arr2[cut2];
            
            if(l1>r2)
            high=cut1-1;
            else if(l2>r1)
            low=cut1+1;
            else 
            return (n1+n2)%2? min(r1,r2) : (max(l1,l2) + min(r1,r2))/2.0;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends