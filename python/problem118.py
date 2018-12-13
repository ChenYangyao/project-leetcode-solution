class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows==0:
            return []
        if numRows==1:
            return [[1]]
        if numRows==2:
            return [[1],[1,1]]
        if numRows>2:
            
            li=[[1],[1,1]]
            
            for i in range(2,numRows):
                li.append([])
                li[i].append(1)
                # li.append([1])
                for k in range(1,i):
                    li[i].append(li[i-1][k]+li[i-1][k-1])
                li[i].append(1)
            return li
                  