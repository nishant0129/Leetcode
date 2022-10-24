//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<vector<int>>v;
      for(int i=0; i<start.size(); i++)
      {
          vector<int>v1;
          v1.push_back(start[i]);
          v1.push_back(end[i]);
          v.push_back(v1);
      }
      vector<vector<int>>ans;
     
      sort(v.begin(),v.end());
      int j=0;
       ans.push_back(v[0]);
      for(int i=1; i<n;i++)
      {
          if(ans[j][1]<v[i][0])
          {
              ans.push_back(v[i]);
             j++;
          }
          else
          {
              ans[j][1]=min(ans[j][1],v[i][1]);
          }
          
      }
    //   for(auto i:v)
    //   {
    //       cout<<i[0]<<" "<<i[1]<<endl;
    //   }
    //   for(auto i:ans)
    //   {
    //       cout<<i[0]<<" "<<i[1]<<endl;
    //   }
      return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends