class Solution {
public:
    long long n;
    long long mod=1000000007;
    long long int recur(string &a,int i,int j,vector<vector<long long>>&dp) {
        if(i>j) {
            return 0;
        }
        if(i==j) {
            return 1;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==a[j]) {
            int l=i+1,r=j-1;
        
            while(l<=r && a[l]!=a[i]){
                l++;
            } 
            while(l<=r && a[r]!=a[j]){
                r--;
            }
            
            if(l>r)
            {
                ans=(ans+2*recur(a,i+1,j-1,dp)+2)%mod; 
// make subsequences by taking random exmaple like bcec it has 5 different subsequences then after adding a same char in starting and end like abceca then different subsequeces are 2*5+2; (2*(middle part)+1)
            }
            else if(l==r)
            {
                ans=(ans+2*recur(a,i+1,j-1,dp)+1)%mod;
                    // similiarly above take example like a[bcacb]a  in bcacb there are 7 dps where as in abcacba 2*7+1 (2*middle part +1)
            }
            else
            {
                // here the example like ababcaba which contain 2 aur more a as in middle part  subtract from recur(l+1 to r-1 )because  the middle part bc is repeated in recur(i+1 to j-1)
                ans= (ans+mod+2*recur(a,i+1,j-1,dp)-recur(a,l+1,r-1,dp))%mod; 
            }
        }
        else
        ans = (ans+mod+recur(a,i,j-1,dp)+recur(a,i+1,j,dp)-recur(a,i+1,j-1,dp))%mod;
        return dp[i][j]=ans;
    }
   int countPalindromicSubsequences(string str)
    {
        n=str.size();
        vector<vector<long long>>dp(n,vector<long long>(n,-1));
        return recur(str,0,n-1,dp)%mod;
        
    }
};