class Solution {
public:
    int dp[10001][10][10][5];
    const int mod=1000000007;
    int solve(string &s,int i,char x,char y,int len)
    {
        if(len==5)
            return 1;
        
        if(i>=s.size())
            return 0;
        if(dp[i][x-'0'][y-'0'][len]!=-1)
            return dp[i][x-'0'][y-'0'][len];
        int take=0;
        if(len==0)
            take= (take+solve(s,i+1,s[i],y,len+1))%mod;
        if(len==1)
            take= (take+solve(s,i+1,x,s[i],len+1))%mod;
        if(len==2)
            take= (take+solve(s,i+1,x,y,len+1))%mod;
        if(len==3 && s[i]==y)
            take =(take+solve(s,i+1,x,y,len+1))%mod;
        if(len==4 && s[i]==x)
            take = (take+solve(s,i+1,x,y,len+1))%mod;
        
         int ntake=  solve(s,i+1,x,y,len);
        
        return dp[i][x-'0'][y-'0'][len]=(take+ntake)%mod;
          
    }
    int countPalindromes(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,'0','0',0);
    }
    
    
};