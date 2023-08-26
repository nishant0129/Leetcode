//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int ls[s.length()]={0};
	    ls[0]=0;
	    int i=1,len=0;
	    while(i<s.length())
	    {
	        if(s[len] == s[i])
	        {
		            len++;
	            ls[i] = len;
            i++;
	        }
	        else
	        {
	            if(len ==0)
	            {
	               // ls[i]=0;
	                i++;
	            }else
	            {
	                len = ls[len-1];
	            }
	        }
	    }
	 
	    return ls[s.length()-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends