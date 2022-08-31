class Solution {
public:
    void dfs(vector<vector<int>>&heights,vector<vector<int>>&oceans,int i,int j,int n,int m)
    {
        if(i<0 || i>n-1 || j<0 || j>m-1) return;
        if(!oceans[i][j])
        {
            oceans[i][j]=1;
            int d=heights[i][j];
            if(i-1>=0 && heights[i-1][j]>=d) 
                dfs(heights,oceans,i-1,j,n,m);
            
            if(i+1<n && heights[i+1][j]>=d) 
                dfs(heights,oceans,i+1,j,n,m);
            
            if(j-1>=0 && heights[i][j-1]>=d) 
                dfs(heights,oceans,i,j-1,n,m);
            
            if(j+1<m && heights[i][j+1]>=d) 
                dfs(heights,oceans,i,j+1,n,m);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0)),atlantic(n,vector<int>(m,0));;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0){
                    if(pacific[i][j]==0)
                    {
                        dfs(heights,pacific,i,j,n,m);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==n-1 || j==m-1){
                    if(atlantic[i][j]==0)
                    {
                        dfs(heights,atlantic,i,j,n,m);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};





// class Solution {
// public:
    
//     void dfs(vector<vector<int>>& grid , int i , int j , int prev , vector<vector<int>>&ocean)
//     {
//         if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
//             return;
//         }
        
//         if(grid[i][j]<prev){
//             return;
//         }
        
//         if(ocean[i][j]==1){
//             return;
//         }
        
//         ocean[i][j]=1;
        
//         dfs(grid,i+1,j,grid[i][j],ocean);
//         dfs(grid,i,j+1,grid[i][j],ocean);
//         dfs(grid,i-1,j,grid[i][j],ocean);
//         dfs(grid,i,j-1,grid[i][j],ocean);
        
        
//     }
    
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
//         vector<vector<int>>ans;
        
//         if(grid.size()==0){
//             return ans;
//         }
        
//         int n = grid.size();
//         int m = grid[0].size();
        
//         vector<vector<int>>pacific(n,vector<int>(m,0));
//         vector<vector<int>>atlantic(n,vector<int>(m,0));
        
//         for(int j=0;j<m;j++)
//         {
//             dfs(grid,0,j,INT_MIN,pacific);
//             dfs(grid,n-1,j,INT_MIN,atlantic);
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             dfs(grid,i,0,INT_MIN,pacific);
//             dfs(grid,i,m-1,INT_MIN,atlantic);
//         }
        
        
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(pacific[i][j]==1 and pacific[i][j]==atlantic[i][j])
//                 {
//                    ans.push_back({i,j});
//                 }
//             }
//         }
        
//         return ans;
        
        
        
//     }
// };