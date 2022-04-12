class Solution {
public:

void gameOfLife(vector<vector<int>>& board)
{
    int n=board.size();
    int m=board[0].size();
    int cnt=0;
    vector<pair<int,int>>v;
    for(int i=0; i<n; i++)
    {

        for(int j=0; j<m; j++)
        {
            cnt=0;
            if(board[i][j]==0)
            {
               if( i+1<n && board[i+1][j]==1 )
                    cnt++;
                if( j+1<m && board[i][j+1]==1 )
                    cnt++;
                if(i+1<n && j+1<m && board[i+1][j+1]==1 )
                    cnt++;
                if( i-1>=0 && j-1>=0 && board[i-1][j-1]==1 )
                    cnt++;
                if( i-1>=0 && board[i-1][j]==1)
                    cnt++;
                if( j-1>=0 && board[i][j-1]==1)
                    cnt++;
                if(  i+1<n && j-1>=0 && board[i+1][j-1]==1)
                    cnt++;
                 if( i-1>=0 && j+1<m && board[i-1][j+1]==1)
                    cnt++;
                
                if(cnt==3)
                {
                    v.push_back({i,j});
                }
            }
            else
            {
                if( i+1<n && board[i+1][j]==1 )
                    cnt++;
                if( j+1<m && board[i][j+1]==1 )
                    cnt++;
                if(i+1<n && j+1<m && board[i+1][j+1]==1 )
                    cnt++;
                if( i-1>=0 && j-1>=0 && board[i-1][j-1]==1 )
                    cnt++;
                if( i-1>=0 && board[i-1][j]==1)
                    cnt++;
                if( j-1>=0 && board[i][j-1]==1)
                    cnt++;
                if(  i+1<n && j-1>=0 && board[i+1][j-1]==1)
                    cnt++;
                 if( i-1>=0 && j+1<m && board[i-1][j+1]==1)
                    cnt++;
                
                if(cnt==2||cnt==3)
                {
                    continue;
                }
                else
                {
                    v.push_back({i,j});
                }
            }
        }
    }
      for(auto i: v)
      {
          if(board[i.first][i.second]==0)
              board[i.first][i.second]=1;
          else
              board[i.first][i.second]=0;
      }
}
};

