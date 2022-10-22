//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void recur(vector<string>&words,int a[],int i, int n,vector<string>&ans,string s)
    {
        if(i==n )
        {
            ans.push_back(s);
            return;
        }
         for(int k=0;k<words[a[i]].size();k++)
         {
            s.push_back(words[a[i]][k]);
            recur(words,a,i+1,n,ans,s);
           s.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
       vector<string> words = {"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       vector<string>ans;
       string s="";
       recur(words,a,0,N,ans,s);
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends