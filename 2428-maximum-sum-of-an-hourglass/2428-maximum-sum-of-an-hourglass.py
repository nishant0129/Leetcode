class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        ans=float('-inf')
        for i in range(n-2):
            for j in range(m-2):
                ans=max(ans,grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]+grid[i+1][j+1])
            # ans=max(ans,res)
        return ans
            
        