class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n==0:
            return 0
        if n==1:
            return 1
        if n==2:
            return 2
        n1=1
        n2=2
        for i in range(3,n+1):
            
            
            n2,n1=n1+n2,n2
            
        return n2