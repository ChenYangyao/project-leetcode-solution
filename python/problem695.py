# wrong and stupid
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        countli = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                countli.append(self.area(grid,i,j))
        return max(countli)
                
                
                
    def area(self,grid,i,j):
        count=0
        if grid[i-1][j] ==1 :
            count=count+1
            self.area(grid,i-1,j)
        if grid[i+1][j] ==1 :
            count=count+1
            self.area(grid,i+1,j)
        if grid[i][j-1] ==1 :
            count=count+1
            self.area(grid,i,j-1)
        if grid[i][j+1] ==1 :
            count=count+1
            self.area(grid,i,j+1)
        return count










# ref:https://leetcode.com/problems/max-area-of-island/discuss/108541/easy-python
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """        
        def area(i,j):
            count=0
            if 0 <= i < m and 0 <= j < n and grid[i][j]==1:
                grid[i][j] = 0 #avoid endless loops
                count=1+area(i-1,j)+area(i+1,j)+area(i,j-1)+area(i,j+1)
                return count
            return 0
        
        countli = []
        m=len(grid)
        n=len(grid[0])
        for i in range(m):
            for j in range(n):
                countli.append(area(i,j))
        return max(countli)
