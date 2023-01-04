//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        unordered_map<string ,int>mp;
        for(auto i:words)
        {
            mp[i]++;
        }
        sort(words.begin(),words.end());
        string ans="";
        for(auto str:words)
        {
            string pref="";
            int cnt=0;
            for(int i=0; i<str.size();i++)
            {
                pref+=str[i];
                if(mp.find(pref)!=mp.end())
                {
                    cnt++;
                }
            }
            if(str.size()==cnt)
            {
                if(ans.size()<cnt)
                ans=str;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends