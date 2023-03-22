//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
       int pre1=accumulate(s1.begin(),s1.end(),0),pre2=accumulate(s2.begin(),s2.end(),0),
           pre3=accumulate(s3.begin(),s3.end(),0);
       
        int i=0,j=0,k=0;
        while(i<n1 and j<n2 and k<n3) {
            if(pre1==pre2 and pre2==pre3) return pre1;
            int mini=min({pre1,pre2,pre3});
            if(pre1>mini) {pre1-=s1[i];i++;}
            if(pre2>mini) {pre2-=s2[j];j++;}
            if(pre3>mini) {pre3-=s3[k];k++;}
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends