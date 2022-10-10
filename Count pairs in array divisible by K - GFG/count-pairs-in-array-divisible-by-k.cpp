//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int a[], int n, int k)
    {
        for(int i=0;i<n;i++) {
            a[i]=a[i]%k;
        }
        long long zero=0,ans=0;
        unordered_map<long long,long long>mp;
        for(int i=0;i<n;i++) {
            if(a[i]==0) {
                ans+=mp[a[i]];
            }else if(mp.find(k-a[i])!=mp.end()) {
                ans+=mp[k-a[i]];
            }
            mp[a[i]]++;
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends