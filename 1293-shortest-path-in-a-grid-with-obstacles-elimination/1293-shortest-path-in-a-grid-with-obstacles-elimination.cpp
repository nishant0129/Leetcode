class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int row=grid.size(), col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,-1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        
        while(!q.empty())
        {
            int size = q.size();
            for(int loop=0;loop<size;++loop)
            {
                int x = q.front()[0];
                int y = q.front()[1];
                int step = q.front()[2];
                int newk = q.front()[3];
                q.pop();
                
                if(x==row-1 and y==col-1)
                    return step;
                
                if(x<0 or x>=row or y<0 or y>=col) 
                    continue; 
                
                if(vis[x][y]!=-1 and vis[x][y]>=newk) 
                    continue; 
                
                if(grid[x][y]==1)
                {
                    if(newk>0)
                        newk--;
                    else continue;
                }
                vis[x][y]=newk;
                for(int i=0; i<4; ++i)
                {
                    int x1 = x+dx[i], y1 = y+dy[i];
                    q.push({x1,y1,step+1,newk});
                }
            }
        }
        return -1;
    }
};