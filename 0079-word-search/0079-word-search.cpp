class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>&grid,string &word,int k)
    {
        int m=grid.size(),n=grid[0].size();
        if(k==word.size())
            return true;
        if(i<0||i>=m||j<0||j>=n||grid[i][j]=='*'||grid[i][j]!=word[k])
            return false;
        char x=grid[i][j];
        grid[i][j]='*';
        bool down=dfs(i+1,j,grid,word,k+1);
        bool right=dfs(i,j+1,grid,word,k+1);
        bool left=dfs(i-1,j,grid,word,k+1);
        bool up=dfs(i,j-1,grid,word,k+1);
        grid[i][j]=x;
        return up||down||right||left;  
    }
    bool exist(vector<vector<char>>& grid, string word) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dfs(i,j,grid,word,0))
                    return  true;
            }
        }
        return false;
    }
};