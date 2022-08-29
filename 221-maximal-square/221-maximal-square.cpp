class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int row=mat.size(),col=mat[0].size();
        int ans=0;
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        for(int i=1;i<=row;i++) {
            for(int j=1;j<=col;j++) {
                if(mat[i-1][j-1]=='1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};


/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int row=mat.size(),col=mat[0].size();
        int ans=0;
        vector<vector<pair<int,int>>>dp(row+1,vector<pair<int,int>>(col+1,pair<int,int>(0,0)));
        for(int i=1;i<=row;i++) {
            for(int j=1;j<=col;j++) {
                if(mat[i-1][j-1]=='1'){
                    dp[i][j].first=min(dp[i-1][j-1].first,dp[i][j-1].first)+1;
                    dp[i][j].second=min(dp[i-1][j-1].second,dp[i-1][j].second)+1;
                }
                ans=max(ans,min(dp[i][j].first,dp[i][j].second));
            }
        }
        return ans*ans;
    }
};
*/

/*
class Solution {
public:
   r int maximalSquare(vector<vector<char>>& mat) {
        int row=mat.size(),col=mat[0].size();
        int ans=0;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(mat[i][j]=='1') {
                    bool found=true;
                    int curx=i;
                    int cury=j;
                    int sq_size=0;
                    while(found and curx<row and cury<col) {
                        int l=curx;
                        int m=cury;
                        for(int count=0;count<=sq_size;count++) {
                            if(mat[l][cury]=='0' or mat[curx][m]=='0') {
                                found=false;
                                break;
                            }else {
                                l-=1;
                                m-=1;
                            }
                        }
                        if(found) {
                            curx+=1;
                            cury+=1;
                            sq_size+=1;
                        }
                        ans=max(ans,sq_size*sq_size);
                    }
                }
            }
        }
        return ans;
    }
};

*/