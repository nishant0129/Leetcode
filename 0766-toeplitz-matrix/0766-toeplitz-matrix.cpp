class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        unordered_map<int,set<int>>mp;
        for(int i=0; i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i-j].insert(matrix[i][j]);
            }
        }
        for(auto i:mp)
        {
            if(i.second.size()>1)
                return false;
        }
        return true;
    }
};