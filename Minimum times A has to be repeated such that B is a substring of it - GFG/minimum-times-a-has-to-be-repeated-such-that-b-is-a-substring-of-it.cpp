//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        int first_prefix=-1;
        for(int i=0;i<A.size();i++) {
            int j,k;
            for(j=i,k=0;j<A.size() and k<B.size();j++,k++) {
                if(A[j]!=B[k]) break;
            }
            if(k==B.size()) return 1;
            if(j==A.size()) {
                first_prefix=k;
                break;
            }
        }
        if(first_prefix==-1) return -1;
        int ans=1,i,j;
        for(i=0,j=first_prefix;j<B.size();i++,j++) {
            if(A[i]!=B[j]) return -1;
            if(i==A.size()-1) {
                i=-1;
                ans++;
            }
        }
        if(i!=0) return ans+1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends