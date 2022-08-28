class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int k = 0; k  < mat.size()-1; k++)
        {
             for(int i = 0; i + 1 < mat.size(); i++)
             {
                for(int j = 0; j < mat[i].size()-1; j++)
                {
                    if(mat[i][j] > mat[i + 1][j + 1])
                        swap(mat[i][j], mat[i + 1][j + 1]); 
                }
             }
        }       
        return mat;
    }
};