//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        int len_a=a.size();
        int len_b=b.size();
        int ans=0;
        for(int i=0;i<len_a;i++) {
            int found=0,ct=1;
            if(a[i]==b[0]) {
                int l=i,r=0;
                while(l<len_a and r<len_b and a[l++]==b[r++]) {
                    if(l==len_a and r!=len_b) {
                        // cout<<"HELLO  ";
                        ct+=1;
                        l=0;
                    }
                    if(r==len_b) {
                        found=1;
                    }
                }
            }
            if(found) {
                return ct;
            }
        }
        return -1;
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