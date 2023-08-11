//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int partition(vector<int>& nums,int low,int high)
    {
         int pivot = nums[high];
        int index = low;
        for(int i=low; i<high; i++)
        {
            if(nums[i]<pivot)
                swap(nums[index++], nums[i]);
            
        }
        swap(nums[index], nums[high]);
        return index; 
    }
    void quicksort(vector<int>&arr,int left ,int right )
    {
         if(left<right)
         {
              int idx = partition(arr,left,right);
              quicksort(arr,left,idx-1);
              quicksort(arr,idx+1,right);
              
         }
    }
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
      
         quicksort(arr,0,n-1);
         return arr;
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends