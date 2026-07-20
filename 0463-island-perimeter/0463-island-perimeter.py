class Solution(object):
    def islandPerimeter(self, grid):
        n=len(grid)
        m= len(grid[0])
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    count += 4
                    if i and grid[i-1][j]:
                        count -= 2
                    if j and grid[i][j-1]:
                        count -= 2
        return count