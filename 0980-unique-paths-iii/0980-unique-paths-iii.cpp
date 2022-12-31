class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int cz)
    {
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]==-1)
            return 0;
        if(grid[i][j]==2)
        {
            if(cz==-1)
                return 1;
            return 0;
        }
     
        grid[i][j]=-1;
        int tp=solve(grid,i+1,j,cz-1)+solve(grid,i,j+1,cz-1)+solve(grid,i-1,j,cz-1)+solve(grid,i,j-1,cz-1);
        grid[i][j]=0;
        return tp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cz=0;
        int nx=0,ny=0;
      for(int i=0;i<grid.size();i++)
      {
          for(int j=0; j<grid[0].size();j++)
          {
              if(grid[i][j]==0)
                  cz++;
              else if(grid[i][j]==1)
              {
                  nx=i;
                  ny=j;
              }
          }
      }
    
       return solve(grid,nx,ny,cz);
        
    }
};