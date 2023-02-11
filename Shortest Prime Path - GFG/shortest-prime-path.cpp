//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    
    void sieve(vector<int>&prime)
    {
        prime[0]=false;
        prime[1]=false;
        for(int i=2; i*i<100000; i++)
        {
            if(prime[i])
            {
                for(int j=2*i; j<100000; j+=i)
                {
                    prime[j]=false;
                }
            }
        }
    }
    int shortestPath(int num1,int num2)
    {   
        // static vector<int>prime;
        // if(prime.empty()) {
        //     prime.assign(10000,true);
        //     sieve(prime);
        // }
        vector<int>prime(100000,true);
        sieve(prime);
        vector<bool>visited(100000,false);
        queue<int>q;
        q.push(num1);
        visited[num1]=true;
        int level=0;
        while(not q.empty()) {
            int st=q.size();
            while(st--) {
                int temp=q.front();
                q.pop();
                
                if(temp==num2) return level;
                
                string org=to_string(temp);
                
                for(int i=0;i<4;i++) {
                    string cpy=org;
                    for(int j='0';j<='9';j++) {
                        cpy[i]=j;
                        int k=stoi(cpy);
                        if(k>=1000 and prime[k] and not visited[k]) {
                            visited[k]=true;
                            q.push(k);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends