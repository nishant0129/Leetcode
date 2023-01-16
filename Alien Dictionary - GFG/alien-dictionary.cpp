//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    
    void solve(int i,vector<int>adj[] , vector<int>&vis,stack<int>&st)
    {
        vis[i]=1;
        for(auto x : adj[i])
        {
            if(vis[x]==0)
            {
                solve(x,adj,vis,st);
            }
        }
        
        st.push(i);
        
    }
    string findOrder(string dict[], int n, int k) {
        //code here
         vector<int>adj[k];
        for(int i=0; i<n-1; i++)
        {
            string s=dict[i];
            string t=dict[i+1];
             int j=0;
            while(j<s.size() && j<t.size())
            {
                if(s[j]!=t[j])
                {
                    adj[s[j]-'a'].push_back(t[j]-'a');
                    break;
                }
                j++;
            }
        }
        
        string ans="";
        vector<int>vis(k,0);
        stack<int>st;
        
        for(int i=0;i<k;i++)
        {
            if(!vis[i])
            {
                solve(i,adj,vis,st);
            }
        }
        
        while(!st.empty())
        {
            char c = st.top() + 'a';
            ans+=c;
            st.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends