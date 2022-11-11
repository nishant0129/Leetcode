class Solution {
public:
    void number_of_island(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&vis)
    {
        int m=grid.size(),n=grid[0].size();
        if(i>=m ||i<0||j>=n||j<0||vis[i][j]||!grid[i][j])
            return ;
        vis[i][j]=1;
        number_of_island(grid,i+1,j,vis);
        number_of_island(grid,i,j+1,vis);
        number_of_island(grid,i-1,j,vis);
        number_of_island(grid,i,j-1,vis);
    }
    int minDays(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int cnt=0;
        for(int i=0; i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                {
                    cnt++;
                    number_of_island(grid,i,j,vis);
                }
            }
        }
        //cout<<cnt<<endl;
        if(cnt!=1)
            return 0;
        else
        {
            vector<pair<int,int>>v;
            for(int i=0; i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        v.push_back({i,j});
                    }
                }
            }
            for(int k=0;k<v.size();k++)
            {
                vector<vector<int>>mat=grid;
                mat[v[k].first][v[k].second]=0;
                vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
                int cnt=0,flag=0;
                for(int i=0; i<grid.size();i++)
                {
                    for(int j=0;j<grid[0].size();j++)
                    {
                        if(mat[i][j]==1&&!visited[i][j])
                        {
                            cnt++;
                            number_of_island(mat,i,j,visited);
                            flag=1;
                        }
                        //cout<<cnt<<endl;
                        if(cnt>1 )
                            return 1;
                    }
                }
                if(flag==0)
                    return 1;
                
            }
        }
        return 2;
    }
};