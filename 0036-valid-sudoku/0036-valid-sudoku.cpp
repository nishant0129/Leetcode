class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int forrow[9][9] = {0}, forcol[9][9] = {0}, forbox[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
        {
            for(int j = 0; j < board[i].size(); ++ j)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    
                    if(forrow[i][num] || forcol[j][num] || forbox[k][num])
                        return false;
                    
                    forrow[i][num] = forcol[j][num] = forbox[k][num] = 1;
                }
            }
        
        }
        return true;
    }
};